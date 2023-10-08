#include <stdio.h>
#include <math.h>
#include "function.h"

void backward_euler_method(double h);

int main(void)
{   
    for(int i=0;i<=6;i++)
    {   
        double h=pow((double)1/2,i);
        printf("以下计算结果基于步长%f\n",h);
        backward_euler_method(h);

    }
    return 0;
}

void backward_euler_method(double h)
{
    double y=y0;
    double _y;
    for(int j=1;j*h<=(end-start);j++)
    {   //针对特定方程的隐式转换为显式
        y = (2*y+h*(start+j*h))/(2+h);
        printf("在点%f的数值解为%f,",start+j*h,y);
        _y = solution(start+j*h);
        printf("在点%f的精确解为%f,",start+j*h,_y);
        printf("绝对误差为%f\n",fabs(_y-y));
    }
    
}