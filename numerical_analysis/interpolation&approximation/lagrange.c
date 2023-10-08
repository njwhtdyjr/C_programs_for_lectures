#include <stdio.h>

double lagrange(int n,double x[],double fx[],double x0);
int main(void)
{
    int n,i;
    printf("请输入lagrange插值节点个数:");
    scanf("%d",&n);
    double x[n],fx[n],x0;
    printf("请输入节点值以及函数相应的值:\n");
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&x[i],&fx[i]);        
    }
    printf("请输入要求函数值的点:");
    scanf("%lf",&x0);
    printf("该点的近似值为:%f",lagrange(n,x,fx,x0));
    return 0;
}
double lagrange(int n,double x[],double fx[],double x0)
{
    double result=0,temp;
    for(int i=0;i<n;i++)
    {   
        temp = 1;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                temp *= (x0-x[j])/(x[i]-x[j]);
            }
        }
        temp *= fx[i];
        result += temp;
    }
    return result;
}