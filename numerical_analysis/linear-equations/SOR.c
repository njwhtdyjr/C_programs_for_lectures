#include <stdio.h>
#define MOD 1000
#define DIV 100
#include <stdlib.h>
#define MAXSTEP 150
#define accuracy 0.001
#include <math.h>
#define relax 0.86

int main()
{   int n,i,j,k;
    printf("请输入矩阵的维数:\n");
    scanf("%d",&n);
    double A[n][n+1],x[n],temp,temp1,temp2,acc;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n+1;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        x[i] = ((double)(rand()%MOD))/DIV;
        
    }
    
    for(k=0;k<MAXSTEP;k++)
    {   
        acc = 0;
        for(i=0;i<n;i++)
        {
            temp1 = 0;
            for(j=0;j<=i-1;j++)
            {
                temp1 -= (A[i][j]/A[i][i])*x[j];
            }
            temp2 = 0;
            for(j=i+1;j<n;j++)
            {
                temp2 -= (A[i][j]/A[i][i])*x[j];
            }
            temp = x[i];
            printf("第%d个分量是%lf\n",i+1,x[i]);
            x[i] = relax*(temp1+temp2+A[i][n]/A[i][i]-(1-1/relax)*x[i]);
            acc += (x[i] - temp)*(x[i] - temp);
        }
        acc = sqrt(acc);
        if(acc<accuracy) break;
    }
    temp = 0;
    for(i=0;i<n;i++)
    {   
        temp += (x[i]-1)*(x[i]-1);
        printf("解向量的第%d个分量为%lf\n",i+1,x[i]);
    }
    printf("总共迭代了%d步\n",k);
    temp = sqrt(temp);
    printf("取2范数的绝对误差为:%lf",temp);

    return 0;
}

















