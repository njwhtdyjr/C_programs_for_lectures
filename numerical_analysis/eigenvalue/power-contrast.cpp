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
    int n,i,j,k,p;
    printf("请输入矩阵的维数:\n");
    scanf("%d",&n);
    double error;
    printf("请输入相对误差:\n");
    scanf("%lf",&error);
    printf("请输入矩阵:\n");
    double A[MAXN][MAXN],A2[MAXN][MAXN];
    double lambda1,lambda2,x[MAXN],u[MAXN],mod=0;

    double temp1,temp2,s[MAXN];
    int M[MAXN];
    double y[MAXN];


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A2[i][j] = A[i][j];
        }
    }

    Start = GetTickCount();

    //选主元的Doolittle分解
    for(i=0;i<n;i++)
    {   temp1 = 0;
        k = i;
        for(j=i;j<n;j++)
        {   temp2 = 0;
            for(p=0;p<i;p++)
            {    
                temp2 += A[j][p]*A[p][i];
            } 
            s[j] = A[j][i] - temp2;
            if(fabs(s[j])>temp1)
            {
                temp1 = fabs(s[j]);
                k = j;
            }
        }
        M[i] = k;

        for(p=0;p<n;p++)
        {   temp2 = A[i][p];
            A[i][p] = A[k][p];
            A[k][p] = temp2;
        }
        temp2 = s[i];
        s[i] = s[k];
        s[k] = temp2;
        
        A[i][i] = s[i];
        for(j=i+1;j<n;j++)
        {   temp2 = 0;
            for(p=0;p<i;p++)
            {    
                temp2 += A[i][p]*A[p][j];
            }
            A[i][j] = A[i][j] - temp2;
            A[j][i] = s[j]/A[i][i];
        }
    }



    //随机产生初始向量
    for(i=0;i<n;i++)
    {
        u[i] = ((double)(rand()%MOD))/DIV;
    }
    //
    for(i=0;i<n;i++)
    {
        mod += u[i]*u[i];
    }
    mod = sqrt(mod);
    for(i=0;i<n;i++)
    {
        x[i] = u[i]/mod;
    }
    
    //求Qy_k-1
    for(j=0;j<n-1;j++)
    {   p = M[j];
        temp2 = x[j];
        x[j] = x[p];
        x[p] = temp2;
    }
    //求y,u
    y[0] = x[0];
    for(i=1;i<n;i++)
    {   temp2 = 0;
        for(j=0;j<i;j++)
            temp2 += A[i][j]*y[j];
        y[i] = x[i] - temp2;
    }
    u[n-1] = y[n-1]/A[n-1][n-1];
    for(i=n-2;i>-1;i--)
    {   temp2 = 0;
        for(j=i+1;j<n;j++)
            temp2 += A[i][j]*u[j];
        u[i] = (y[i]-temp2)/A[i][i];
    }

    for(i=0;i<n;i++)
    {   x[i] = 0;
        for(j=0;j<n;j++)
        {
            x[i] += u[j] * A2[i][j];
        }
    }

    lambda1 = 0;
    for(i=0;i<n;i++)
    {
        lambda1 += x[i] * u[i];
    }


    mod = 0;
    for(i=0;i<n;i++)
    {
        mod += u[i]*u[i];
    }
    mod = sqrt(mod);
    for(i=0;i<n;i++)
    {
        x[i] = u[i]/mod;
    }

    //求Qy_k-1
    for(j=0;j<n-1;j++)
    {   p = M[j];
        temp2 = x[j];
        x[j] = x[p];
        x[p] = temp2;
    }
    //求y,u
    y[0] = x[0];
    for(i=1;i<n;i++)
    {   temp2 = 0;
        for(j=0;j<i;j++)
            temp2 += A[i][j]*y[j];
        y[i] = x[i] - temp2;
    }
    u[n-1] = y[n-1]/A[n-1][n-1];
    for(i=n-2;i>-1;i--)
    {   temp2 = 0;
        for(j=i+1;j<n;j++)
            temp2 += A[i][j]*u[j];
        u[i] = (y[i]-temp2)/A[i][i];
    }

    for(i=0;i<n;i++)
    {   x[i] = 0;
        for(j=0;j<n;j++)
        {
            x[i] += u[j] * A2[i][j];
        }
    }

    lambda2 = 0;
    for(i=0;i<n;i++)
    {
        lambda2 += x[i] * u[i];
    }



    //迭代
    while(fabs((1/lambda1)-(1/lambda2))/fabs((1/lambda2)) > error)
    {
        lambda1 = lambda2;
        
        mod = 0;
        for(i=0;i<n;i++)
        {
            mod += u[i]*u[i];
        }
        mod = sqrt(mod);
        for(i=0;i<n;i++)
        {
            x[i] = u[i]/mod;
        }
        //求Qy_k-1
        for(j=0;j<n-1;j++)
        {   p = M[j];
            temp2 = x[j];
            x[j] = x[p];
            x[p] = temp2;
        }
        //求y,u
        y[0] = x[0];
        for(i=1;i<n;i++)
        {   temp2 = 0;
            for(j=0;j<i;j++)
                temp2 += A[i][j]*y[j];
            y[i] = x[i] - temp2;
        }
        u[n-1] = y[n-1]/A[n-1][n-1];
        for(i=n-2;i>-1;i--)
        {   temp2 = 0;
            for(j=i+1;j<n;j++)
                temp2 += A[i][j]*u[j];
            u[i] = (y[i]-temp2)/A[i][i];
        }

        
        for(i=0;i<n;i++)
        {   x[i] = 0;
            for(j=0;j<n;j++)
            {
                x[i] += u[j] * A2[i][j];
            }
        }

        lambda2 = 0;
        for(i=0;i<n;i++)
        {
            lambda2 += x[i] * u[i];
        }       

    }

    printf("A的按模最小的特征值为%lf\n",1/lambda2);
    for(i=0;i<n;i++)
    {
        printf("属于%lf的特征向量的第%d个分量是%lf\n",1/lambda2,i+1,x[i]);
    }


    End = GetTickCount();
    cout<<(End-Start)<<endl;  


    return 0;
}