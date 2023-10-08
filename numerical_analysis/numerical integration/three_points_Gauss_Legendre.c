#include <stdio.h>
#include "function3.h"

void three_Gauss_Legendre(void);

int main(void)
{
    three_Gauss_Legendre();
    return 0;
}

void three_Gauss_Legendre(void)
{
    double real=ofunction(r)-ofunction(l);
    double approx=(r-l)/2*(5.0/9*function((r+l)/2+(r-l)/2*(-sqrt(3.0/5)))+8.0/9*function((r+l)/2+(r-l)/2*0.0)+5.0/9*function((r+l)/2+(r-l)/2*(sqrt(3.0/5))));
    printf("利用三点Gauss-Legendre公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));
}