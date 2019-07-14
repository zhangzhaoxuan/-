#include<iostream>
#include"myQueue.h"
using namespace std;
int option(int percent[]) {
	int i = 0, choice = rand() % 100 + 1, perc;//����1~100�����������ĳһ�����˶�����
	for (perc = percent[0]; perc < choice; perc += percent[i + 1], i++);
	return i;
}
int main() {
	int arrivals[] = { 15,20,25,10,30 };//��¼�����±������˿͵���İٷֱ�
	int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};//��¼��������ʱ��ķֲ�
	int clerk[] = {0,0,0,0};//�ĸ�����Ա������Ϊ��λ��¼����ʱ��
	int numOfClerk = sizeof(clerk) / sizeof(int);
	int customers=0, t=0, i=0, numOfMunite=100, x;
	double maxWait = 0.0, currWait = 0.0, thereIsLine = 0.0;
	ArrayQueue<int>q;
	cout.precision(2);//���þ���
	for (t = 1; t < numOfMunite; t++) {
		cout << "t=" << t;
		for (i = 0; i < numOfClerk; i++)
			if (clerk[i] < 60)
				clerk[i] = 0;
			else
				clerk[i] -= 60;
		customers = option(arrivals);
		for (i = 0; i < customers; i++)//�˿ͽ�������Ŷ�
		{
			x = option(service) * 10;
			q.enqueue(x);
			currWait += x;
		}
		for (int i = 0; i < numOfClerk && !q.isempty();)
		
			if (clerk[i] < 60) {
				x = q.dequeue();//�Ӷ����г���������
				clerk[i] += x;
				currWait -= x;

				
			}
			else i++;
		if (!q.isempty()) {
			thereIsLine++;
			cout << "wait=" << currWait / 60.0;
			if (maxWait < currWait)
				maxWait = currWait;
		}
		else cout << "wait=0";
	}
	cout << "\n for" << numOfClerk << "clerks,there was a line"
		<< thereIsLine / numOfMunite * 100 << "% of the time\n"//�����Ŷӵ�ʱ��ռ��ʱ��İٷֱ�,���м��㷨
		<< "max wait time was " << maxWait / 60.0 << "min";
	return 0;
}
