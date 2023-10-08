#include <stdio.h>
#include <math.h>
#include "function.h"

void predictor_corrector_method(double h);

int main(void)
{   
    for(int i=0;i<=6;i++)
    {   
        double h=pow((double)1/2,i);
        printf("以下计算结果基于步长%f\n",h);
        predictor_corrector_method(h);

    }
    return 0;
    
}

void predictor_corrector_method(double h)
{
    double y=y0;
    double temp_y;
    double _y;
    for(int j=1;j*h<=(end-start);j++)
    {   
        temp_y = y+h*function(start+(j-1)*h,y);
        y = y+h/2*(function(start+(j-1)*h,y)+function(start+j*h,temp_y));
        printf("在点%f的数值解为%f,",start+j*h,y);
        _y = solution(start+j*h);
        printf("在点%f的精确解为%f,",start+j*h,_y);
        printf("绝对误差为%f\n",fabs(_y-y));
    }
    
}
