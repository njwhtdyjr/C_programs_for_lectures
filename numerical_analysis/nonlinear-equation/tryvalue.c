#include <stdio.h>
#include "common.h"

int main(void)
{
    double step = up-function(up)*(down-up)/(function(down)-function(up));
    while(fabs(function(step))>= ERROR)
    {       
        printf("x的值为%f\nf(x)的值为%f\n",step,function(step));
        if(function(step)*function(up) < 0)
        down = step;
        else 
        up = step;
        step = up-function(up)*(down-up)/(function(down)-function(up));
        k += 1;
        if(k == MAX-1) break;

    }
    printf("最后x的值为%f\nf(x)的值为%f\n",step,function(step));
    printf("迭代了%d步",k+1);
    return 0;   
}