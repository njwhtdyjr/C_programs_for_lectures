#include <stdio.h>
#define MAXK 50
double y=1;
double power(double x,int pow[],int i)
{   double p;
    if(i == 0)
    {   if(pow[i] == 1)
        {   y *= x;
            return x;
        }else return x;
    }
    i--;
    p = power(x,pow,i);
    if(pow[i+1]==1)
    {
        y *= p*p;
    }
    return p*p;
}
int main()
{   int pow[MAXK];
    double x;
    int n,m,i=0;
    printf("请输入x:\n");
    scanf("%lf",&x);
    printf("请输入x的幂的次数:\n");
    scanf("%d",&n);
    m = n;
    while(m!=0)
    {
        if(m%2)
        {
            pow[i] = 1;
        }else pow[i] = 0;
        m = m/2;
        i++;
    }
    i--;
    power(x,pow,i);
    printf("%lf",y);
    return 0;
}
