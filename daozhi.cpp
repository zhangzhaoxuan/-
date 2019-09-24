#include<iostream>
using namespace std;
class LinkNode
{
public:
	int data;
	LinkNode* link;
	LinkNode(const int& el, LinkNode* ptr = 0) {
		data = el;
		link = ptr;
	}
};
class linkList
{
private:
	LinkNode* head, * tail;
	LinkNode * currPtr;
	int pos;
public:
	linkList() { head=0, tail = 0; pos = 0; currPtr = 0; };
	~linkList() {};
	void insert(int value)
	{
		if (head == NULL)
			head = new LinkNode(value);
		else
		{
			LinkNode* p = head;
			while (p->link != 0)
				p = p->link;
			p->link= new LinkNode(value);
		}
	}
	void show()
	{
		currPtr = head;
		while (currPtr != NULL)
		{
			cout << currPtr->data;
			currPtr = currPtr->link;
		}
	}
	LinkNode* reverge()
	{
		LinkNode* p = head->link;
		LinkNode* q = p->link;
		head->link = q;
		p->link = head;
		while (q != NULL)
		{
			q = q->link;
			head->link->link = p;
			p = head->link;
			head->link = q;
			
		}
	
		return p;
	}
	void setHead(LinkNode* head)
	{
		this->head = head;
	}
};
int main()
{
	linkList l;
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.show();
	cout << endl;
	l.setHead(l.reverge());
	l.show();
}