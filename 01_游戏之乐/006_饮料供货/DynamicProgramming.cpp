/*************************************************************************
    > File Name: DynamicProgramming.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-23 15:49:22
 ************************************************************************/

#include<iostream>
using namespace std;
//第一列为饮料的容量（均为2的次幂）
//第二列为饮料最多的供应量
//第三列为饮料的满意度
int drink[10][3] = 
{
    1,4,2,
    1,6,2,
    2,3,1,
    4,7,5,
    4,2,1,
    4,10,2,
    8,1,6,
    8,1,7,
    16,2,4,
    16,1,3
};
//Opt(V',i)表示从第i,i+1,i+2,……,9,10种饮料中，算出总量为V'的方案中满意度之和的最大值
//按照取第i种饮料的个数来递归。
int Opt(int V,int n)
{
    if ((V == 0) || (n == 0))
        return 0;
    int max = Opt(V,n-1);
    for (int i = 1 ; (i < drink[n-1][1] + 1) && (V - i * drink[n-1][0] >= 0) ; i++)
    {
        int tmp = i * drink[n-1][2] + Opt(V - i * drink[n-1][0],n-1);
        if (tmp > max)
            max = tmp;
    }
    return max;
}
int main()
{
    //题目要求的即是在给定的饮料量的情况下，求出满意度最高的方式
    int VMax = 70;
    cout<<"result:"<<Opt(VMax,10)<<endl;
    return 0;
}
