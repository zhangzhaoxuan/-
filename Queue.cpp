#include<iostream>
using namespace std;
template<class T,int size=100>
class ArrayQueue {
public:
	ArratQueue()
	{
		first = last = -1;
	}
	void enqueue(T);
	T dequeue();
	bool isFull()
	{
		return first == 0&&last==size-1||first==last+1;//循环数组队列满的两种情况，第一种是队首与队尾相遇，即“追尾”，第二种是队尾自然增长到头
	}
	bool isempty()
	{
		return first == -1;
	}
private:
	int first, last;
	T data[size];
};
template<class T,int size>
void ArrayQueue<T, size>::enqueue(T el)
{
	if (!isFull())
		if (last == -1 || last == size - 1) {//先判断特殊位置即首部和尾部
			data[0] = el;
			last = 0;
			if (first == -1)
				first = 0;
		}
		else
			data[++last] = el;
	else
		cout << "the queue is full" << endl;

}
template<class T, int size>
T ArrayQueue<T, size>::dequeue()//出队
{
	if (!empty())
	{
		T tmp;
		tmp = data[first];
		if (first == last)
		{
			first = last = -1;
		}
		if (first = size - 1)
			first = 0;
		else
			first++;
		return tmp;
	}
	else
		return NULL;
	
}