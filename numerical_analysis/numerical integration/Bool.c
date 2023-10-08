#include <stdio.h>
#include "function3.h"

void Bool(void);

int main(void)
{   
    Bool();
    return 0;
}

void Bool(void)
{
    double real=ofunction(r)-ofunction(l),approx=(r-l)/90*(7*function(l)+32*function((3*l+r)/4)+12*function((r+l)/2)+32*function((l+3*r)/4)+7*function(r));
    printf("利用Bool公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}