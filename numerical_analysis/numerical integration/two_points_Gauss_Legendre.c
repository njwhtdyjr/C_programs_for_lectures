#include <stdio.h>
#include "function2.h"

void two_Gauss_Legendre(void);

int main(void)
{   
    two_Gauss_Legendre();
    return 0;
}

void two_Gauss_Legendre(void)
{
    double real=ofunction(r)-ofunction(l);
    double approx=(r-l)/2*(function((r+l)/2+(r-l)/2*(-1/sqrt(3)))+function((r+l)/2+(r-l)/2*(1/sqrt(3))));
    printf("利用两点Gauss-Legendre公式求出的积分值为:%f\n",approx);
    printf("真实积分值为:%f\n",real);
    printf("积分绝对误差为:%f\n",fabs(real-approx));


}