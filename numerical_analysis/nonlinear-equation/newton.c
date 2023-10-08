#include <stdio.h>
#include "common.h"


int main(void)
{
    while(fabs(newton(x)-x)>=ERROR)
    {
       printf("x的值为%f\nx-φ(x)的值为%f\n",x,x-newton(x));
       x = newton(x);
       k += 1;
       if(k == MAX-1) break;
    } 
    printf("最后x的值为%f\nx-φ(x)的值为%f\n",x,x-newton(x));
    printf("迭代了%d步",k);







    return 0;
}