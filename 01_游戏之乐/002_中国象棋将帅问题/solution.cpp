/*************************************************************************
    > File Name: solution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-17 23:12:19
 ************************************************************************/

#include<iostream>
using namespace std;
void UpdateRight(int &b,int n)
{
    b = (b & 240) ^ n;
}
void UpdateLeft(int &b,int n)
{
    b = (b & 15) ^ (n << 4);
}
int GetLeft(int b)
{
    return (b & 240) >> 4;
}
int GetRight(int b)
{
    return b & 15;
}
int main()
{
    int b = 0;
    for (UpdateLeft(b,1) ; GetLeft(b) <= 9 ; UpdateLeft(b,(GetLeft(b)+1)))
        for (UpdateRight(b,1) ; GetRight(b) <= 9 ; UpdateRight(b,(GetRight(b)+1)))
            if (GetLeft(b)%3 != GetRight(b)%3)
                cout<<"A="<<GetLeft(b)<<"   "<<"B="<<GetRight(b)<<endl;
    return 0;
}

