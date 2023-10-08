#include <math.h>
double start=0,end=3;
double y0=1;

double start1=0,end1=0.2;
double x0=6,y10=4;

double function(double t,double y)
{
    return (t-y)/2;
}

double solution(double t)
{
    return 3*exp(-t/2)-2+t;
}
double function1(double t,double x,double y)
{
    return x+2*y;
}
double function2(double t,double x,double y)
{
    return 3*x+2*y;
}

double solution1(double t)
{
    return 4*exp(4*t)+2*exp(-t);
}
double solution2(double t)
{
    return 6*exp(4*t)-2*exp(-t); 
}