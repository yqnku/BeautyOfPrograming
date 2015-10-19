/*************************************************************************
    > File Name: otherSolution.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-10-17 23:45:28
 ************************************************************************/

#include<iostream>
using namespace std;
void method1()
{
    cout<<"Method1:\n";
    int i = 81;
    while (i--)
    {
        if (i / 9 % 3 == i % 9 % 3)
            continue;
        cout<<"A="<<(i / 9 + 1)<<"   "<<"B="<<(i % 9 + 1)<<endl;
    }

}
void method2()
{
    cout<<"Method2:\n";
    struct
    {
        int a;
        int b;
    }i;
    for (i.a = 1 ; i.a <= 9 ; i.a++)
        for (i.b = 1 ; i.b <= 9 ; i.b++)
            if (i.a % 3 != i.b % 3)
                cout<<"A="<<i.a<<"   "<<"B="<<i.b<<endl;
}
int main()
{
    method1();
    method2();
    return 0;
}

