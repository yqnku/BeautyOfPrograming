/*************************************************************************
    > File Name: solution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-18 15:43:00
 ************************************************************************/

#include<iostream>
using namespace std;
int Calc1(int N)
{
    int num = 0;
    while (N)
    {
        if (N % 10 == 1)
            num++;
        N /= 10;
    }
    return num;
}
int CalcNum(int N)
{
    int num = 0;
    for (int i = 1 ; i <= N ; i++)
    {
        num += Calc1(i);
    }
    return num;
}
int main()
{
    cout<<CalcNum(12)<<endl;
    return 0;
}

