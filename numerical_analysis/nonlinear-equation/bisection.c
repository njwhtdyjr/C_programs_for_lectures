#include <stdio.h>
#include "common.h"


int main(void)
{   
    while (fabs(function((up+down)/2)) >= ERROR )
    {   
        printf("x的值为%f\nf(x)的值为%f\n",(up+down)/2,function((up+down)/2));
        if(function((up+down)/2)*function(up) < 0)
           down = (up+down)/2;
        else 
        up = (up+down)/2;
        k += 1;
        if(k == MAX-1) break;
    } 
    printf("最后x的值为%f\nf(x)的值为%f\n",(up+down)/2,function((up+down)/2));
    printf("迭代了%d步",k+1);
    
    return 0; 
}

