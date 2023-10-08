#include <stdio.h>
#include "function.h"
#include <math.h>

void newton(void);


int main(void)
{   
    newton();
    return 0;
}

void newton(void)
{
    double x=1;
    while(fabs(derivative(x))>=error && k<100)
    {
        x = x - derivative(x)/second_derivative(x);
        printf("x:%f\nf(x):%f\n",x,function(x));
        k++;
    }
    printf("极小值点:%f\n极小值:%f\n",x,function(x));
    printf("迭代了%d步",k);
}


