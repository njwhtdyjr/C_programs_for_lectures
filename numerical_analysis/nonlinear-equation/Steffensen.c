#include <stdio.h>
#include "common.h"


int main(void)
{
    double y=next(x),z=next(y);
    while(fabs(pow((y-x),2)/(z-2*y+x))>=ERROR)
    {
        printf("x的值为%f\nx-φ(x)的值为%f\n",x,pow((y-x),2)/(z-2*y+x));
        x = x-pow((y-x),2)/(z-2*y+x);
        y = next(x);
        z = next(y);
        k += 1;
       if(k == MAX-1) break;
    }
    printf("最后x的值为%f\nx-φ(x)的值为%f\n",x,pow((y-x),2)/(z-2*y+x));
    printf("迭代了%d步",k);





    return 0;
}

