#include <stdio.h>
#include "function.h"
#include <math.h>

void golden_search(void);

int main(void)
{   
    golden_search();
    return 0;
}

void golden_search(void)
{
    double l=left,m,r=right;
    double temp;
    int flag;
    m = l + ((3-sqrt(5))/2)*(r-l);
    temp = l + ((sqrt(5)-1)/2)*(r-l);
    if(function(temp)<function(m))
    {
        l = m;
        m = temp;
        r = r;
        flag = 0;
    }
    else
    {
        l = l;
        r = temp;
        m = m;
        flag = 1;
    }
    k++;
    while(r-l>=error && k<100)
    {
        if(flag == 0)
        {
            temp = l + ((sqrt(5)-1)/2)*(r-l);
            printf("x为:%f\nf(x)为:%f\n",temp,function(temp));
            
            if(function(temp)<function(m))
            {
                l = m;
                r = r;
                m = temp;
                flag = 0;

            }
            else
            {
                l = l;
                r = temp;
                m = m;
                flag = 1;
            }
        }
        else
        {
           temp = l + ((3-sqrt(5))/2)*(r-l);
           printf("x为:%f\nf(x)为:%f\n",temp,function(temp));
           if(function(temp)<function(m))
            {
                l = l;
                r = m;
                m = temp;
                flag = 1;
            }
            else
            {
                l = temp;
                r = r;
                m = m;
                flag = 0;
            }
        }
        k++;
    }
    printf("极小值点:%f\n极小值:%f\n",m,function(m));
    printf("迭代了%d步",k);

}