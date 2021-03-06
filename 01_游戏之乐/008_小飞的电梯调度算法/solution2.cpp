/*************************************************************************
    > File Name: solution2.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-25 10:11:24
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    //楼层
    const int N = 6;
    //r[N-1]表示在从第2层到第N层每层要停的人数
    int r[N-1] = {5,3,7,1,6};
    //利用相邻楼层间的需要爬楼梯数的差值的关系
    //N1,N2,N3分别表示，第i层之前，第i层，第i层之后的人数
    //从第2层开始
    int N1 = 0;
    int N2 = r[0];
    int N3 = 0;
    for (int i = 1 ; i < N-1 ; i++)
    {
        N3 += r[i];
    }
    //跟起始值没有关系，设为0
    int steps = 0;
    int min = 0;
    //记录结果
    int x = 1;
    //从第2层开始
    for (int i = 0 ; i < N-1 ; i++)
    {
        steps += N1 - N2 - N3;
        cout<<steps<<"   "<<endl;
        if (steps < min)
        {
            min = steps;
            x = i+2;
        }
        if (i == N-2)
            break;
        N1 = N1 + r[i];
        N2 = r[i+1];
        N3 = N3 - r[i+1];
    }
    cout<<"results:"<<x<<endl;
    return 0;
}

