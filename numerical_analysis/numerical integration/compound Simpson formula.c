#include <stdio.h>
#include "function1.h"

void com_Simpson(void);

int main(void)
{   
    com_Simpson();
    return 0;
}

void com_Simpson(void)
{
    double real=ofunction(r)-ofunction(l);
    double approx=0;
    approx += h/3*(function(l)+function(r));
    for(int i=1;i<=((n-1)/2)-1;i++)
    {
        approx += 2*h/3*function(l+2*i*h);
        approx += 4*h/3*function(l+(2*i-1)*h);
    }
    approx += 4*h/3*function(l+(2*((n-1)/2)-1)*h);
    printf("利用m=%d的复化Simpson公式求出的积分值为:%f\n",(n-1)/2,approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}

