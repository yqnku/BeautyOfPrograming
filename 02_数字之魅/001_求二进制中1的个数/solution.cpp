/*************************************************************************
    > File Name: solution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-09 13:19:34
 ************************************************************************/

#include<iostream>
using namespace std;
//第一种是最直接的方法
int Count(int v)
{
    int num = 0;
    while (v)
    {
        if (v%2 == 1)
            num++;
        v = v/2;
    }
    return num;
}
void Change(int v)
{
    int *p = new int[8];
    int i = 0;
    while (v)
    {
        p[i] = v%2;
        v = v/2;
        i++;
    }
    for (int j = i ; j < 8 ; j++)
        p[j] = 0;
    cout<<"二进制表示为：";
    for (int k = 7 ; k >=0 ; k-- )
        cout<<p[k];
    cout<<endl;
}
//二三两种方法都是用位运算
int WeiMethod(int v)
{
    int num = 0;
    while (v)
    {
        num += v &0x01;
        v >>= 1;
    }
    return num;
}
int Method3(int v)
{
    int num = 0;
    while (v)
    {
        v &= (v-1);
        num++;
    }
    return num;
}
//空间换时间，查表法
int main()
{
    int n;
    cout<<"请输入一个0~255之间的数：";
    cin>>n;
    if ((n >= 0) && (n <= 255))
    {
        Change(n);
        cout<<"1的个数为："<<Count(n)<<endl;
        cout<<"1的个数为："<<WeiMethod(n)<<endl;
        cout<<"1的个数为："<<Method3(n)<<endl;
    }
    else
    {
        cout<<"输入的数非法"<<endl;
    }
    return 0;
}

