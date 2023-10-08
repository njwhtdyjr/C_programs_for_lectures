#include <stdio.h>


double newton(int n,double x[],double fx[],double x0);
int main(void)
{
    int n,i;
    printf("请输入newton插值节点个数:");
    scanf("%d",&n);
    double x[n],fx[n],x0;
    printf("请输入节点值以及函数相应的值:\n");
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&x[i],&fx[i]);        
    }
    printf("请输入要求函数值的点:");
    scanf("%lf",&x0);
    printf("该点的近似值为:%f",newton(n,x,fx,x0));
    

    return 0;
}
double newton(int n,double x[],double fx[],double x0)
{
    double result=0,temp=1;
    for(int i=0;i<n;i++)
    {
        result += fx[0]*temp;
        temp *= (x0-x[i]);
        for(int j=0;j<n-1-i;j++)
        {
            fx[j] = (fx[j]-fx[j+1])/(x[j]-x[i+j+1]);
        }
    }
    return result;
}