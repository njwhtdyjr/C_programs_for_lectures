#include <stdio.h>
#include "function2.h"

void Simpson(void);

int main(void)
{   
    Simpson();
    return 0;
}

void Simpson(void)
{   
    double real=ofunction(r)-ofunction(l),approx=(r-l)/6*(function(l)+4*function((r+l)/2)+function(r));
    printf("利用Simpson公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}