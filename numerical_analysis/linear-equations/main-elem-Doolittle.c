#include <stdio.h>
#define MAXN 50
#include <math.h>
int main()
{   //for循环的花括号请不要省略!!!
    int M[MAXN];
    printf("请输入系数矩阵的维数:\n");
    int n;
    scanf("%d",&n);
    int i,j,k,p;
    double A[MAXN][MAXN];
    double b[MAXN],y[MAXN],x[MAXN];
    double temp1,temp2,s[MAXN];
    //输入数据
    for (i=0;i<n;i++)
        for(j=0;j<=n;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    for(i=0;i<n;i++)
    {
        b[i] = A[i][n];
    }

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
    //求Qb
    for(j=0;j<n-1;j++)
    {   p = M[j];
        temp2 = b[j];
        b[j] = b[p];
        b[p] = temp2;
    }
    //求y,x
    y[0] = b[0];
    for(i=1;i<n;i++)
    {   temp2 = 0;
        for(j=0;j<i;j++)
            temp2 += A[i][j]*y[j];
        y[i] = b[i] - temp2;
    }
    x[n-1] = y[n-1]/A[n-1][n-1];
    for(i=n-2;i>-1;i--)
    {   temp2 = 0;
        for(j=i+1;j<n;j++)
            temp2 += A[i][j]*x[j];
        x[i] = (y[i]-temp2)/A[i][i];
    }
    //输出结果
    for(i=0;i<n;i++)
    {
        printf("%lf\n",x[i]);
    }
    return 0;



}