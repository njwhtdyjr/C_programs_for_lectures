#include <math.h>

double l=1,r=6;
int n=11;
double h=0.5;

double function(double x){
    return 2+sin(2*sqrt(x));
}

double ofunction(double x)
{
    return 2*x-sqrt(x)*cos(2*sqrt(x))+sin(2*sqrt(x))/2;
}
