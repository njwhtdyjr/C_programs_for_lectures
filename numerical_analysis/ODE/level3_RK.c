#include <stdio.h>
#include <math.h>
#include "function.h"

void level3_RK(double h);

int main(void)
{   
    for(int i=0;i<=6;i++)
    {   
        double h=pow((double)1/2,i);
        printf("以下计算结果基于步长%f\n",h);
        level3_RK(h);

    }
    return 0;
}

void level3_RK(double h)
{
    double y=y0;
    double K1,K2,K3;
    double _y;
    for(int j=1;j*h<=(end-start);j++)
    {   
        K1=function(start+(j-1)*h,y);
        K2=function(start+(j-1)*h+0.5*h,y+0.5*h*K1);
        K3=function(start+j*h,y-h*K1+2*h*K2);
        y = y+h/6*(K1+4*K2+K3);
        printf("在点%f的数值解为%f,",start+j*h,y);
        _y = solution(start+j*h);
        printf("在点%f的精确解为%f,",start+j*h,_y);
        printf("绝对误差为%f\n",fabs(_y-y));
    }
    
}
