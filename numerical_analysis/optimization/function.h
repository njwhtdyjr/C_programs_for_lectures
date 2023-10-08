#include <math.h>

double left=0,right=1;
double middle = 0.618;
double error=1e-4;
int k=0;
double function(double x)
{
    return pow(x,2)-sin(x);
}

double derivative(double x)
{
    return 2*x-cos(x);
}

double second_derivative(double x)
{
    return 2+sin(x);
}