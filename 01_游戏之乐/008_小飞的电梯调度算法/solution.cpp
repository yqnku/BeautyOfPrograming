/*************************************************************************
    > File Name: solution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-25 09:48:26
 ************************************************************************/

#include<iostream>
using namespace std;
//用于表示两个楼层的差值
int Abs(int i,int j)
{
    int res = i-j;
    if (res < 0)
        res = -res;
    return res;
}
int main()
{
    //楼层
    const int N = 6;
    //r[N-1]表示在从第2层到第N层每层要停的人数
    int r[N-1] = {5,3,7,1,6};
    int min = 65535;
    for (int i = 0 ; i < N ; i++)
    {
        int steps = 0;
        for (int j = 0 ; j < N-1 ; j++)
        {
            steps += Abs(i+1,j+2) * r[j];
        }
        cout<<steps<<"   "<<endl;
        if (steps < min)
            min = steps;
    }
    cout<<"results:"<<min<<endl;
    return 0;
}

