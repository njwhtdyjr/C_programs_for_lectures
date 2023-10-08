#include <stdio.h>

double myPow(double x, int n);

int main(void)
{
    return 0;
}

double myPow(double x,int n)
{
    if(n==0)return 1;
    unsigned n1;
    if(n<0)
    {   
        
        x = 1/x;
        n1 = (unsigned)(-(long long)(n));
    }
    else n1 = (unsigned)n;

    if(n1%2==0)
    {   
        double temp = myPow(x,(int)(n1/2));
        return temp*temp;
    }
    else
    {
        double temp = myPow(x,(int)((n1-1)/2));
        return temp*temp*x;
    }
}