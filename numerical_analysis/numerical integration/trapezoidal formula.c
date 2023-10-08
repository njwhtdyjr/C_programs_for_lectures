#include <stdio.h>
#include "function2.h"

void trapezoidal(void);




int main(void)
{
    trapezoidal();
    return 0;
}

void trapezoidal(void)
{   
    double real=ofunction(r)-ofunction(l),approx=(r-l)/2*(function(r)+function(l));
    printf("利用梯形公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}





