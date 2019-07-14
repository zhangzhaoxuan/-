#include<iostream>
#include"myQueue.h"
using namespace std;
int option(int percent[]) {
	int i = 0, choice = rand() % 100 + 1, perc;//产生1~100的随机数就是某一天来了多少人
	for (perc = percent[0]; perc < choice; perc += percent[i + 1], i++);
	return i;
}
int main() {
	int arrivals[] = { 15,20,25,10,30 };//记录数组下标数量顾客到达的百分比
	int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};//记录服务所需时间的分布
	int clerk[] = {0,0,0,0};//四个银行员工以秒为单位记录交易时间
	int numOfClerk = sizeof(clerk) / sizeof(int);
	int customers=0, t=0, i=0, numOfMunite=100, x;
	double maxWait = 0.0, currWait = 0.0, thereIsLine = 0.0;
	ArrayQueue<int>q;
	cout.precision(2);//设置精度
	for (t = 1; t < numOfMunite; t++) {
		cout << "t=" << t;
		for (i = 0; i < numOfClerk; i++)
			if (clerk[i] < 60)
				clerk[i] = 0;
			else
				clerk[i] -= 60;
		customers = option(arrivals);
		for (i = 0; i < customers; i++)//顾客进入队列排队
		{
			x = option(service) * 10;
			q.enqueue(x);
			currWait += x;
		}
		for (int i = 0; i < numOfClerk && !q.isempty();)
		
			if (clerk[i] < 60) {
				x = q.dequeue();//从队列中出来被服务
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
		<< thereIsLine / numOfMunite * 100 << "% of the time\n"//有人排队的时间占总时间的百分比,银行家算法
		<< "max wait time was " << maxWait / 60.0 << "min";
	return 0;
}
