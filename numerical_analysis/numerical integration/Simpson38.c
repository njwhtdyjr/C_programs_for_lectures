#include <stdio.h>
#include "function.h"

void Simpson38(void);

int main(void)
{   
    Simpson38();
    return 0;
}

void Simpson38(void)
{
    double real=ofunction(r)-ofunction(l),approx=(r-l)/8*(function(l)+3*function((2*l+r)/3)+3*function((l+2*r)/3)+function(r));
    printf("利用Simpson3/8公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}