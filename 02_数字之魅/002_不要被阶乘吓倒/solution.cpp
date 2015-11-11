/*************************************************************************
    > File Name: solution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-11 23:36:09
 ************************************************************************/

#include<iostream>
using namespace std;
int CalcZero(int n)
{
    int ret = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        int j = i;
        while (j % 5 == 0)
        {
            ret++;
            j /= 5;
        }
    }
    return ret;
}
int CalcZero2(int n)
{
    int ret = 0;
    while (n)
    {
        n /=5;
        ret += n;
    }
    return ret;
}
int main()
{
    int n;
    cout<<"请输入一个正整数n\n";
    cin>>n;
    cout<<n<<"!的末尾的0的个数为"<<CalcZero(n)<<endl;
    cout<<n<<"!的末尾的0的个数为"<<CalcZero2(n)<<endl;
    return 0;
}

