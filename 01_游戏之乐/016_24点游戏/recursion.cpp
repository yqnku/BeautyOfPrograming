/*************************************************************************
    > File Name: recursion.cpp
    > Author: yq
    > Mail: xiqian013@live.com 
    > Created Time: 2015-11-02 13:53:44
 ************************************************************************/

#include<iostream>
using namespace std;
double Abs(double a,double b)
{
    return a>b?a-b:b-a;
}
void Show(double p[],int size)
{
    for (int i = 0 ; i < size ; i++)
        cout<<p[i]<<"   ";
    cout<<endl;
}
bool f(double p[],int size)
{
    if (size == 1)
    {
        if (Abs(p[0],24) < 0.001)
        {
            return true;
        }
        else
            return false;
    }
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = i+1 ; j < size ; j++)
        {
            double *newP1 = new double[size-1];
            int count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP1[count] = p[k];
                    count++;
                }
            }
            newP1[size-2] = p[i]+p[j];
            if (f(newP1,size-1))
            {
                Show(newP1,size-1);
            }
                
            double *newP2 = new double[size-1];
            count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP2[count] = p[k];
                    count++;
                }
            }
            newP2[size-2] = p[i]-p[j];
            if(f(newP2,size-1))
            {
                Show(newP2,size-1);
            }

            double *newP3 = new double[size-1];
            count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP3[count] = p[k];
                    count++;
                }
            }
            newP3[size-2] = p[j]-p[i];
            if(f(newP3,size-1))
            {
                Show(newP3,size-1);
            }

            double *newP4 = new double[size-1];
            count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP4[count] = p[k];
                    count++;
                }
            }
            newP4[size-2] = p[i]*p[j];
            if (f(newP4,size-1))
            {
                Show(newP4,size-1);
            }

            if (p[j] == 0)
                return false;
            double *newP5 = new double[size-1];
            count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP5[count] = p[k];
                    count++;
                }
            }
            newP5[size-2] = p[i]/p[j];
            if (f(newP5,size-1))
            {
                Show(newP5,size-1);
            }

            if (p[i] == 0)
                return false;
            double *newP6 = new double[size-1];
            count = 0;
            for (int k = 0 ; k < size ; k++)
            {
                if ((k != i) && (k != j))
                {
                    newP6[count] = p[k];
                    count++;
                }
            }
            newP6[size-2] = p[j]/p[i];
            if (f(newP6,size-1))
            {
                Show(newP6,size-1);
            }
        }
    }
}
int main()
{
    double a[4] = {1,2,3,4};
    cout<<f(a,4)<<endl;
    return 0;
}

