#include <stdio.h>
#include "function1.h"

void com_trape(void);

int main(void)
{
    com_trape();
    return 0;
}

void com_trape(void)
{
    double real=ofunction(r)-ofunction(l);
    double approx=0;
    approx += h/2*(function(l)+function(r));
    for(int i=1;i<=n-2;i++)
    {
        approx += h*function(l+h*i);
    }
    printf("利用n=%d的复化梯形公式求出的积分值为:%f\n",n-1,approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}