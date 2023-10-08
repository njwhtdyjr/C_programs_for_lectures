#include <stdio.h>
#define MAXN 100
#include <stdlib.h>
#define MOD 1000
#define DIV 100
#include <math.h>
#include <windows.h>
#include <iostream>


using namespace std;
int main()
{   
    DWORD Start,End;
    
    //输入数据
    int n,i,j,r,sgn;
    printf("请输入矩阵的维数:\n");
    scanf("%d",&n);
    double error;
    printf("请输入相对误差:\n");
    scanf("%lf",&error);
    printf("请输入矩阵:\n");
    double A[MAXN][MAXN];
    double lambda1,lambda2,x[MAXN],u[MAXN],mod=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }

    Start = GetTickCount();

    for(i=0;i<n;i++)
    {
        u[i] = ((double)(rand()%MOD))/DIV;
    }

    //
    for(i=0;i<n;i++)
    {
        if(fabs(u[i])>mod)
        {
            mod = fabs(u[i]);
            r = i;
        }
    }  
    for(i=0;i<n;i++)
    {
        x[i] = u[i]/mod;
    }
    if(u[r]>0)
    {   
        sgn = 1; 
    }else sgn = -1;

    for(i=0;i<n;i++)
    {   u[i] = 0;
        for(j=0;j<n;j++)
        {
            u[i] += x[j] * A[i][j];
        }
    }
    lambda1 = sgn*u[r];

    mod = 0;
    for(i=0;i<n;i++)
    {
        if(fabs(u[i])>mod)
        {
            mod = fabs(u[i]);
            r = i;
        }
    }  
    for(i=0;i<n;i++)
    {
        x[i] = u[i]/mod;
    }
    if(u[r]>0)
    {   
        sgn = 1; 
    }else sgn = -1;

    for(i=0;i<n;i++)
    {   u[i] = 0;
        for(j=0;j<n;j++)
        {
            u[i] += x[j] * A[i][j];
        }
    }
    lambda2 = sgn*u[r];

    while(fabs(lambda1-lambda2)/fabs(lambda2) > error)
    {
        lambda1 = lambda2;
        mod = 0;
        for(i=0;i<n;i++)
        {
            if(fabs(u[i])>mod)
            {
                mod = fabs(u[i]);
                r = i;
            }
        }  
        for(i=0;i<n;i++)
        {
            x[i] = u[i]/mod;
        }
        if(u[r]>0)
        {   
            sgn = 1; 
        }else sgn = -1;

        for(i=0;i<n;i++)
        {   u[i] = 0;
            for(j=0;j<n;j++)
            {
                u[i] += x[j] * A[i][j];
            }
        }
        lambda2 = sgn*u[r];

    }


    printf("A的按模最大的特征值为%lf\n",lambda2);
    for(i=0;i<n;i++)
    {
        printf("属于%lf的特征向量的第%d个分量是%lf\n",lambda2,i+1,x[i]);
    }
    
    End = GetTickCount();
    cout<<(End-Start)<<endl;  
    return 0;
}