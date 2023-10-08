#include <stdio.h>
#include <math.h>
#include "function.h"

void level3_RK(double h);

int main(void)
{   
      
        double h=0.02;
        printf("以下计算结果基于步长%f\n",h);
        level3_RK(h);

    
    return 0;
}

void level3_RK(double h)
{
    double y=y10;
    double x=x0;
    double F1,F2,F3;
    double G1,G2,G3;
    double _y,_x;
    for(int j=1;j*h<=(end1-start1);j++)
    {   
        F1=function1(start1+(j-1)*h,x,y);
        G1=function2(start1+(j-1)*h,x,y);
        F2=function1(start1+(j-1)*h+0.5*h,x+0.5*h*F1,y+0.5*h*G1);
        G2=function2(start1+(j-1)*h+0.5*h,x+0.5*h*F1,y+0.5*h*G1);
        F3=function1(start1+j*h,x-h*F1+2*h*F2,y-h*G1+2*h*G2);
        G3=function2(start1+j*h,x-h*F1+2*h*F2,y-h*G1+2*h*G2);
        y = y+h/6*(G1+4*G2+G3);
        x = x+h/6*(F1+4*F2+F3);
        printf("在点%f的数值解为x:%f,y:%f,",start1+j*h,x,y);
        _y = solution2(start1+j*h);
        _x = solution1(start1+j*h);
        printf("在点%f的精确解为x:%f,y:%f,",start1+j*h,_x,_y);
        printf("绝对误差为x:%f,y:%f,",fabs(_x-x),fabs(_y-y));
        printf("相对误差为x:%f,y:%f\n",fabs(_x-x)/fabs(_x),fabs(_y-y)/fabs(_y));
    }
    
}
