#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MOD 1000
#define DIV 100
#include <iomanip>
#include <iostream>

//传递数组会改变数组，声明变量时注意有没有分配内存空间，没有就单独声明

using namespace std;
double power(double q);
double inversepower(double q);
double det();


int max(int i, int j)
{
    if(i<=j)
    {
        return j;
    }else return i;
}


int min(int i,int j)
{
    if(i<=j)
    {
        return i;
    }else return j;
}





int  main()
{      
    
        
    double lambda1,lambda501,lambdas;
    lambda1 = power(0.0);
    lambda501 = power(lambda1);
    lambdas = inversepower(0.0);
    cout<<setiosflags(ios::scientific)<<setprecision(11)<<lambda1<<endl;
    cout<<setiosflags(ios::scientific)<<setprecision(11)<<lambda501<<endl;
    cout<<setiosflags(ios::scientific)<<setprecision(11)<<lambdas<<endl;

    int i;
    for(i = 1;i<=39;i++)
    {
        cout<<setiosflags(ios::scientific)<<setprecision(11)<<inversepower(lambda1+i*((lambda501-lambda1)/40))<<endl;
    }
    if(fabs(lambda1)>fabs(lambda501))
    {
        cout<<setiosflags(ios::scientific)<<setprecision(11)<<fabs(lambda1/lambdas)<<endl;
    }else cout<<setiosflags(ios::scientific)<<setprecision(11)<<fabs(lambda501/lambdas)<<endl;


    cout<<setiosflags(ios::scientific)<<setprecision(11)<<det()<<endl;
             
    return 0;
}

double power(double q)
{   
    int n=501,i,j,r,sgn,r1=2,s1=2;
    double S[3];
    double A[5][501];
    double lambda1,lambda2;
    double error = 1e-12;
    double x[501],u[501],mod=0; 


    //输入数据,A用带状数组的压缩存储
    i = 0;
    for(j=2;j<n;j++)
    {
        A[i][j] = -0.064;
    }
    i = 1;
    for(j=1;j<n;j++)
    {
        A[i][j] = 0.16;
    }
    i = 2;
    for(j=0;j<n;j++)
    {
        A[i][j] = (1.64-0.024*(j+1))*sin(0.2*(j+1))-0.64*exp(0.1/(j+1));
    }
    i = 3;
    for(j=0;j<n-1;j++)
    {
        A[i][j] = 0.16;
    }
    i = 4;
    for(j=0;j<n-2;j++)
    {
        A[i][j] = -0.064;
    }

    //原点平移
    i = 2;
    for(j=0;j<n;j++)
    {
        A[i][j] -= q;
    }

    //取随机向量
    for(i=0;i<n;i++)
    {
        u[i] = ((double)(rand()%MOD))/DIV;
    }



    //迭代一轮
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
        for(j=max(0,i-2);j<=min(n-1,i+2);j++)
        {
            u[i] += x[j] * A[i-j+s1][j];
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
        for(j=max(0,i-2);j<=min(n-1,i+2);j++)
        {
            u[i] += x[j] * A[i-j+s1][j];
        }
    }
    lambda2 = sgn*u[r];
    
    
    
    //幂法的迭代
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
            for(j=max(0,i-2);j<=min(n-1,i+2);j++)
            {
                u[i] += x[j] * A[i-j+s1][j];
            }
        }
        
        lambda2 = sgn*u[r];
        
    }
    return lambda2+q;
}
//反幂法
double inversepower(double q)
{

    int n=501,i,j,r,sgn,r1=2,s1=2;
    double lambda1,lambda2;
    int k,p;
    double A[5][501];
    double error = 1e-12;
    double x[501],u[501],mod=0; 
    
    i = 0;
    for(j=2;j<n;j++)
    {
        A[i][j] = -0.064;
    }
    i = 1;
    for(j=1;j<n;j++)
    {
        A[i][j] = 0.16;
    }
    i = 2;
    for(j=0;j<n;j++)
    {
        A[i][j] = (1.64-0.024*(j+1))*sin(0.2*(j+1))-0.64*exp(0.1/(j+1));
    }
    i = 3;
    for(j=0;j<n-1;j++)
    {
        A[i][j] = 0.16;
    }
    i = 4;
    for(j=0;j<n-2;j++)
    {
        A[i][j] = -0.064;
    }


    i = 2;
    for(j=0;j<n;j++)
    {
        A[i][j] -= q;
    }



    //带状分解
    for(k=0;k<n;k++)
    {
        for(j=k;j<= min(k+s1,n-1);j++)
        {
            for(i=max(max(0,k-r1),j-s1);i<=k-1;i++)
            {
                A[k-j+s1][j] -=  A[k-i+s1][i]*A[i-j+s1][j];
            }
        }
        for(i=k+1;i<=min(k+r1,n-1);i++)
        {
            for(j=max(max(0,i-r1),k-s1);j<=k-1;j++)
            {
                A[i-k+s1][k] -= A[i-j+s1][j]*A[j-k+s1][k];
            }
            A[i-k+s1][k] /= A[s1][k];            
        }
        


    }
    //取随机向量
    for(i=0;i<n;i++)
    {
        u[i] = ((double)(rand()%MOD))/DIV;
    }


    
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

    //计算解向量
    for(i=1;i<n;i++)
    {
        for(j=max(0,i-r1);j<=i-1;j++)
        {
            x[i] -= A[i-j+s1][j]*x[j];
        }
    }
    u[n-1] = x[n-1]/A[s1][n-1];
    for(i=n-2;i>-1;i--)
    {
        for(j=i+1;j<=min(i+s1,n-1);j++)
        {
            x[i] -= A[i-j+s1][j]*u[j];
        }
        u[i] = x[i]/A[s1][i];
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

    //计算解向量
    for(i=1;i<n;i++)
    {
        for(j=max(0,i-r1);j<=i-1;j++)
        {
            x[i] -= A[i-j+s1][j]*x[j];
        }
    }
    u[n-1] = x[n-1]/A[s1][n-1];
    for(i=n-2;i>-1;i--)
    {
        for(j=i+1;j<=min(i+s1,n-1);j++)
        {
            x[i] -= A[i-j+s1][j]*u[j];
        }
        u[i] = x[i]/A[s1][i];
    }


    lambda2 = sgn*u[r];
    
    while(fabs((1/lambda1)-(1/lambda2))/fabs((1/lambda2)) > error)
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

        //计算解向量
        for(i=1;i<n;i++)
        {
            for(j=max(0,i-r1);j<=i-1;j++)
            {
                x[i] -= A[i-j+s1][j]*x[j];
            }
        }
        u[n-1] = x[n-1]/A[s1][n-1];
        for(i=n-2;i>-1;i--)
        {
            for(j=i+1;j<=min(i+s1,n-1);j++)
            {
                x[i] -= A[i-j+s1][j]*u[j];
            }
            u[i] = x[i]/A[s1][i];
        }


        lambda2 = sgn*u[r];

    }
    return 1/lambda2 + q ;
}

double det()
{
    double det = 1.0;
    double A[5][501];
    int i,j,n=501,k,s1=2,r1=2;
    i = 0;
    for(j=2;j<n;j++)
    {
        A[i][j] = -0.064;
    }
    i = 1;
    for(j=1;j<n;j++)
    {
        A[i][j] = 0.16;
    }
    i = 2;
    for(j=0;j<n;j++)
    {
        A[i][j] = (1.64-0.024*(j+1))*sin(0.2*(j+1))-0.64*exp(0.1/(j+1));
    }
    i = 3;
    for(j=0;j<n-1;j++)
    {
        A[i][j] = 0.16;
    }
    i = 4;
    for(j=0;j<n-2;j++)
    {
        A[i][j] = -0.064;
    }



    //带状分解
    for(k=0;k<n;k++)
    {
        for(j=k;j<= min(k+s1,n-1);j++)
        {
            for(i=max(max(0,k-r1),j-s1);i<=k-1;i++)
            {
                A[k-j+s1][j] -=  A[k-i+s1][i]*A[i-j+s1][j];
            }
        }
        for(i=k+1;i<=min(k+r1,n-1);i++)
        {
            for(j=max(max(0,i-r1),k-s1);j<=k-1;j++)
            {
                A[i-k+s1][k] -= A[i-j+s1][j]*A[j-k+s1][k];
            }
            A[i-k+s1][k] /= A[s1][k];            
        }    
    }
    i = 2;
    for(j=0;j<n;j++)
    {
        det *= A[i][j];
    }
    return det;

}