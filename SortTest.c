#include<stdio.h>
int a[1000];
int main()
{
    int n,i,t;
    for(int i=0;i<1000;i++)//初始化桶
        a[i]=0;
   n=10;
    for(i=0;i<10;i++)
    {
        scanf("%d",&t);
        if(a[t]==1)//去重
            continue;
        else
        a[t]=1;
    }
    for(int i=0;i<1000;i++)
    {
        if(a[i]==1)
        printf("%d ",i);
    }
    return 0;
}
