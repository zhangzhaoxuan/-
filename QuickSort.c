#include<stdio.h>
int a[101],n;
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right)//递归终止条件
        return;
    temp=a[left];
    i=left;
    j=right;
    while(i!=j)
    {
        //先从右往左找
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        if(i<j)//没有相遇，执行交换
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);
    quicksort(i+1,right);
}
int main()
{
    int i,j,t;
    n=10;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
