#include <stdio.h>
#include "common.h"


int main(void)
{   
    double temp;
    while(fabs((temp = secant(x0,x1))-x1)>=ERROR)
    {  
       printf("x的值为%f\nx-φ(x)的值为%f\n",x1,x1-temp);
       
       x0 = x1;
       x1 = temp;
       k += 1;
       if(k == MAX-1) break;
    } 
    printf("最后x的值为%f\nx-φ(x)的值为%f\n",x1,x1-temp);
    printf("迭代了%d步",k);

    return 0;
}