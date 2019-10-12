#include <iostream>
#include<sstream>
using namespace std;
template<class T>
class LinkNode
{
public:
	T data;
	LinkNode* link;
	LinkNode(const T& el=-1, LinkNode<T>* ptr = 0) {
		data = el;
		link = ptr;
	}
};
template<class T>
class Stack {
public:
	void Clear();//清空
	bool Push(const T item);
	bool Pop(T& item);
	bool Top(T& item);
	bool isEmpty();
	bool isFull();
};
template<class T>
class ArrayStack :public Stack<T>
{
private:
	int maxSize;
	int top;
	T* st;
public:
	ArrayStack(int size)
	{
		maxSize = size;
		top = -1;
		st = new T[maxSize];
	}
	ArrayStack()
	{
		top = -1;
	}
	~ArrayStack()
	{
		delete[]st;
	}
	void Clear()
	{
		top = -1;
	}
	bool Push(const T item) {
		if (top == maxSize - 1)
		{
			cout << "Stack is overflow";
			return false;
		}
		else
		{
			st[++top] = item;
			return true;
		}
	}
	bool Pop(T& item) {
		if (top == -1)
		{
			return false;
		}
		else
		{
			item = st[top--];
			return true;
		}
	}
	bool Top(T& item)
	{
		if (top == -1)
		{
			return false;
		}
		else
		{
			item = st[top];
			return true;
		}
	}
};
template<class T>
class LinkStack :public Stack<T>
{
private:
	LinkNode<T>* top;
	int size;
public:
	LinkStack(int s) {
		top = NULL;
		size = s;
	}
	~LinkStack()
	{
		Clear();
	}
	void Clear() {
		while (top != NULL) {
			LinkNode<T>* temp = top;
			top = top->link;
			delete temp;
		}
		size = 0;
	}
	bool Push(const T Item) {
		LinkNode<T>* temp = new LinkNode<T>(Item, top);
		top = temp;
		size++;
		return true;
	}
	bool Pop() {
		LinkNode <T>* tmp;
		if (size == 0) {
			cout << "Stack is empty" << endl;
			return false;
		}
		tmp = top->link;
		delete top;
		top = tmp;
		size--;
		return true;
	}

	T Top() {
		T item;
		if (size == 0) {
			cout << "Stack is empty" << endl;
			return false;
		};
		try {
			if (top == nullptr)
				throw 0;
			else
			item = top->data;
		}
		catch (int) {
			cout << "表达式出错！";
			exit(0);
		}
		return item;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
};
double cal(double a1, double a2, char s) {
	if (s == '+')
		return a1 + a2;
	else if (s == '-')
		return a1 - a2;
	else if (s == '*')
		return a1 * a2;
	else if (s == '/')
	{
		if (a2 == 0) {
			cout << "除数不能是0";
			return -1;
		}
		else
			return a2 / a1;
		
	}
	else {
		cout << "无法识别的操作符号";
		return -1;
	}

}
int priority(char s) {
	int p = 0;
	switch (s)
	{
	case '+':
		p = 1;
		break;
	case '-':
		p = 1;
		break;
	case '*' :
		p = 2;
		break;
	case '/':
		p = 2;
		break;
	case '(':
		p = 3;
		break;
	default:
		break;
	}
	return p;
}
bool calculate(string e) {
	char post[40];
	int j = 0;
	LinkStack<char>s1(20);
	LinkStack<double>s2(20);
	for (int i = 0; i < e.length(); i++) {
		
		if ((e[i] >= '0' && e[i] <= '9') || e[i] == '.')
		{	
			post[j++] = e[i];
			if (e[i + 1] == '+' || e[i + 1] == '-' || e[i + 1] == '*' || e[i + 1] == '/')
			post[j++] = '\0';  
			
		}
		else if (e[i] == '(')
			s1.Push(e[i]);
		else if (e[i] == ')') {
			while (s1.Top() != '(') {
				post[j++] = s1.Top();
				s1.Pop();
			}
			s1.Pop();
		}
		else {
			if (s1.isEmpty())
				s1.Push(e[i]);
			else {
				while (priority(e[i]) <= priority(s1.Top()) && priority(s1.Top()) != 3) {
					post[j++] = s1.Top();
					s1.Pop();
				}
				s1.Push(e[i]);
			}
		}
		
	}
	while (!s1.isEmpty()) {
		post[j++] = s1.Top();
		s1.Pop();
	}
	post[j] = '#';
	cout << "后缀表达式为：" << endl;
	for (int i = 0; post[i] != '#'; i++) {
		cout << post[i];
	}
	j = 0;
	int i = 0;
	string num;
	while (post[j] != '#') {
		if (post[j] == '\0')
		{
			double n;
			istringstream iss(num);
			iss >> n;
			s2.Push(n);
			num="";
			j++;
		}
		if (post[j] >= '0' && post[j] <= '9' || post[j] == '.')
		{
			num += post[j++];
			if (post[j] == '+' || post[j] == '-' || post[j] == '*' || post[j] == '/')
			{
				double n;
				istringstream iss(num);
				iss >> n;
				s2.Push(n);
				num = "";
				
			}
		}
		else {
			try {
				
				double can1 = s2.Top();
				s2.Pop();
				
				double can2 = s2.Top();
				s2.Pop();
				double jieguo = cal(can1, can2, post[j++]);
				if (jieguo == -1)
			{
				cout << "除数不能为0！"<<endl;
				return false;
			}
				else
			{
				s2.Push(jieguo);
			}
			}
			catch (exception& e) {
				cout << e.what();
				return 0;
			}	
		}
	}
	cout << endl;
	cout << s2.Top();
	return true;
}
int main()
{
	string ele;
	cin >> ele;
	calculate(ele);
}


