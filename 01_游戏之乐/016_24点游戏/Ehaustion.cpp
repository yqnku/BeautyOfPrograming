/*************************************************************************
    > File Name: Exhaustion.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-01 13:23:43
 ************************************************************************/

#include<iostream>
using namespace std;
double Abs(double a,double b)
{
    return a>b?a-b:b-a;
}
double Calc(double a,double b,int f)
{
    switch(f)
    {
        case 0:
            return a+b;
        case 1:
            return a-b;
        case 2:
            return a*b;
        case 3:
            if (b == 0)
                return 10000;
            return a/b;
        default:
            return 10000;
    }
}
char ShowFun(int q)
{
    switch(q)
    {
        case 0:
            return '+';
        case 1:
            return '-';
        case 2:
            return '*';
        case 3:
            return '/';
        default:
            break;
    }
    return 'a';
}
void Show(int p[],int i,int j,int k,int l,int m,int n,int o,int index)
{
    switch(index)
    {
        case 0:
            cout<<p[i]<<ShowFun(m)<<'('<<p[j]<<ShowFun(n)<<'('<<p[k]<<ShowFun(o)<<p[l]<<"))"<<endl;
            break;
        case 1:
            cout<<p[i]<<ShowFun(m)<<"(("<<p[j]<<ShowFun(n)<<p[k]<<')'<<ShowFun(o)<<p[l]<<')'<<endl;
            break;
        case 2:
            cout<<'('<<p[i]<<ShowFun(m)<<p[j]<<')'<<ShowFun(n)<<'('<<p[k]<<ShowFun(o)<<p[l]<<')'<<endl;
            break;
        case 3:
            cout<<'('<<p[i]<<ShowFun(m)<<'('<<p[j]<<ShowFun(n)<<p[k]<<"))"<<ShowFun(o)<<p[l]<<endl;
            break;
        case 4:
            cout<<"(("<<p[i]<<ShowFun(m)<<p[j]<<')'<<ShowFun(n)<<p[k]<<')'<<ShowFun(o)<<p[l]<<endl;
            break;
        default:
            return;
    }
}
bool is24(int p[])
{
    for (int i = 0 ; i < 4 ; i++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            if (j == i)
                continue;
            for (int k = 0 ; k < 4 ; k++)
            {
                if ((k == i) || (k == j))
                    continue;
                for (int l = 0 ; l < 4 ; l++)
                {
                    if((l == i) || (l == j) || (l == k))
                        continue;
                    for (int m = 0 ; m < 4 ; m++)
                    {
                        for (int n = 0 ; n < 4 ; n++)
                        {
                            for (int o = 0 ; o < 4 ; o++)
                            {
                                double tmp = 0;
                                double tmp1 = 0;
                                tmp = Calc(p[k],p[l],o);
                                tmp = Calc(p[j],tmp,n);
                                tmp = Calc(p[i],tmp,m);
                                if (Abs(tmp,24) < 0.1)
                                {
                                    Show(p,i,j,k,l,m,n,o,0);
                                    return true;
                                }

                                tmp = Calc(p[j],p[k],n);
                                tmp = Calc(tmp,p[l],o);
                                tmp = Calc(p[i],tmp,m);
                                if (Abs(tmp,24) < 0.1)
                                {
                                    Show(p,i,j,k,l,m,n,o,1);
                                    return true;
                                }

                                tmp = Calc(p[i],p[j],m);
                                tmp1 = Calc(p[k],p[l],o);
                                tmp = Calc(tmp,tmp1,n);
                                if (Abs(tmp,24) < 0.1)
                                {
                                    Show(p,i,j,k,l,m,n,o,2);
                                    return true;
                                }
                                
                                tmp = Calc(p[j],p[k],n);
                                tmp = Calc(p[i],tmp,m);
                                tmp = Calc(tmp,p[l],o);
                                if (Abs(tmp,24) < 0.1)
                                {
                                    Show(p,i,j,k,l,m,n,o,3);
                                    return true;
                                }

                                tmp = Calc(p[i],p[j],m);
                                tmp = Calc(tmp,p[k],n);
                                tmp = Calc(tmp,p[l],o);
                                if (Abs(tmp,24) < 0.1)
                                {
                                    Show(p,i,j,k,l,m,n,o,4);
                                    return true;
                                }
                            }
                        }
                    }  
                }
            }
        }
    }
    return false;
}

int main()
{
    int a[4] = {5,5,5,1};
    int b[4] = {3,3,7,7};
    int c[4] = {3,3,8,8};
    int d[4] = {4,4,10,10};
    int e[4] = {1,4,5,6};
    int f[4] = {3,8,8,10};
    int g[4] = {4,4,10,10};
    int h[4] = {9,9,6,2};
    is24(a);
    is24(b);
    is24(c);
    is24(d);
    is24(e);
    is24(f);
    is24(g);
    is24(h);
    return 0;
}

