#include <stdio.h>
#include "function.h"
#include <math.h>
void parabolic(void);

int main(void)
{
    parabolic();
    return 0;
}

void parabolic(void)
{
    double l=left,m=middle,r=right;
    double temp;
    while(r-l>=error && k<100)
    {   
        temp = 0.5*(((pow(m,2)-pow(r,2))*function(l)+(pow(r,2)-pow(l,2))*function(m)+(pow(l,2)-pow(m,2))*function(r))/((m-r)*function(l)+(r-l)*function(m)+(l-m)*function(r)));
        printf("x:%f\nf(x):%f\n",temp,function(temp));
        if(temp>m)
        {
            if(function(temp)<function(m))
            {
                l = m;
                m = temp;
                r = r;
            }
            else
            {
                l = l;
                r = temp;
                m = m;
            }
        }
        else
        {   
            if(function(temp)<function(m))
            {
                l = l;
                r = m;
                m = temp;
            }
            else
            {
                l = temp;
                m = m;
                r = r;
            }
        }
        k++;
    }
    printf("极小值点:%f\n极小值:%f\n",m,function(m));
    printf("迭代了%d步",k);
}