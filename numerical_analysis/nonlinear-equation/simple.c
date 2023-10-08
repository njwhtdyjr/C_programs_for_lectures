#include <stdio.h>
#include "common.h"

int main(void){
    
    while(fabs(next(x)-x)>=ERROR)
    {
       printf("x的值为%f\nx-φ(x)的值为%f\n",x,x-next(x));
       x = next(x);
       k += 1;
       if(k == MAX-1) break;
    } 
    printf("最后x的值为%f\nx-φ(x)的值为%f\n",x,x-next(x));
    printf("迭代了%d步",k);

    return 0;
}

