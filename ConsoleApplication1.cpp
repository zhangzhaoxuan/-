#include <iostream>
#include<stack>
using namespace std;
template<class T>
class LinkNode
{
public:
	T data;
	LinkNode* link;
	LinkNode(const T& el, LinkNode<T>* ptr = 0) {
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
		size =s;
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
		tmp = top->next;
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
		item = top->data;
		return item;
	}
};

bool transaction(int x) {
	if (x > 9)
		return false;
	cout << "请输入转换的数字";
	int n;
	cin >> n;
	ArrayStack<int>s(10);
	while (n>=x) {
		s.Push(n % x);
		n /= x;
	}
	s.Push(n);
	cout << "转化为" << x << "进制" << endl;
	int i;
	while (s.Pop(i))
		cout << i;
	cout << endl;
	return true;

}
void check(string str) {
	stack<char> check;
	for (int i = 0; i < str.length(); i++) {
		//cout << check_string[i];
		if (((str[i] == ')') && (check.top() == '(')) || ((str[i] == ']') && (check.top() == '[')) || ((str[i] == '}') && (check.top() == '{'))) {
			check.pop();
		}
		else {
			check.push(str[i]);
		}
	}
	if (check.empty()) {
		cout << "这是一个合法的串" << endl;
	}
	else {
		cout << "这不是一个合法的串" << endl;
	}
}


int main()
{
	ArrayStack<int> s1(20);
	LinkStack<char> s2(50);
	s1.Push(1);
	s1.Push(2);
	s2.Push('D');
	s2.Push('U');
	s2.Push('T');
	cout << s2.Top()<<endl;
	int i;
	s1.Top(i);
	cout << i<<endl;
	transaction(2);
	cout << "请输入要检测的字符串";
	string s;
	cin >> s;
	check(s);
}

