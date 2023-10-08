#include <stdio.h>
#include "function.h"
#include <math.h>

void quadratic(void);

int main(void)
{
    quadratic();
    return 0;
}

void quadratic(void)
{
    double x=1,h=-0.1;
    double f1,f2,f3;
    while(fabs(h)>=error && k<100)
    {
        f1 = function(x);
        f2 = function(x+h);
        f3 = function(x+2*h);
        h = h*((4*f2-3*f1-f3)/(4*f2-2*f1-2*f3));
        x = x + h;
        printf("x:%f\nf(x):%f\n",x,function(x));
        k++;
    }
    printf("极小值点:%f\n极小值:%f\n",x,function(x));
    printf("迭代了%d步",k);
}