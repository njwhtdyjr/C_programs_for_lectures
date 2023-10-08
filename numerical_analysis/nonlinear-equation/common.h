#define MAX 100
#define ERROR 1e-5
#include <math.h>
//区间逼近法需要
double up = 2 ,down = 1;
int k = 0;
double function(double x)
{
    return exp(-100*x)-1;
}
//简单迭代法和steffensen迭代法、牛顿迭代法需要
double x = -0.51;
double next(double x)
{
    return pow(x,3)-1;
}
double newton(double x)
{
    return x-(exp(-100*x)-1)/(-100*exp(-100*x));
}
//割线法
double x0 = -0.51, x1 = 0.49;
double secant(double x0,double x1)
{
    return x1-function(x1)*(x1-x0)/(function(x1)-function(x0));
}

