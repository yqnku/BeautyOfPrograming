/*************************************************************************
    > File Name: ReverseSort.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-19 15:43:33
 ************************************************************************/

#include<iostream>
using namespace std;
//找到烙饼中最大的数
int FindMaxIndex(int p[],int n,int size)
{
    int index = n;
    for (int i = n+1 ; i < size ; i++)
        if (p[i] > p[index])
            index = i;
    return index;
}
//每次把最大的翻转到最底下
void Reverse(int p[],int n,int size)
{
    int *tmp = new int[size-n];
    for (int i = 0 ; i < size-n ; i++)
        tmp[i] = p[size-1-i];
    for (int i = 0 ; i < size-n ; i++)
        p[n+i] = tmp[i];
}
void DoubleReverse(int p[],int n,int size)
{
    int maxIndex = FindMaxIndex(p,n,size);
    Reverse(p,maxIndex,size);
    Reverse(p,n,size);
}
void Show(int p[],int size)
{
    for (int i = 0 ; i < size ; i++)
        cout<<p[i]<<"   ";
    cout<<endl;
}
int main()
{
    int a[10] = {3,2,1,6,5,4,9,8,7,0};
    for(int i = 0 ; i < 9 ; i++)
        DoubleReverse(a,i,10);
    Show(a,10);
    return 0;
}

