#include <math.h>

double l=0,r=1;
double function(double x)
{
    return 1+exp(-x)*sin(4*x);
}


double ofunction(double x)
{
    return 1.0/17*(exp(-x))*(17*exp(x)*x-sin(4*x)-4*cos(4*x));
}
