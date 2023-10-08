#include <stdio.h>
#define MOD 1000
#define DIV 100
#include <stdlib.h>
#define MAXSTEP 1000
#define accuracy 0.00001
#include <math.h>
#define relax 1.9

int main(void)
{   

    int m,n;
    printf("请输入方程的个数与未知元的个数:\n");
    scanf("%d %d",&m,&n);
    double A[m][n+1],x[n],temp3,temp1,temp2,acc;
    printf("请按行输入待求解超定方程组的数据:\n");
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<n+1;j++)
            scanf("%lf",&A[i][j]);
    double A0[n][n+1],temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {   temp = 0;
            for(k=0;k<m;k++)
            {
                temp += A[k][i]*A[k][j];
            }
            A0[i][j] = temp;
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
                temp1 -= (A0[i][j]/A0[i][i])*x[j];
            }
            temp2 = 0;
            for(j=i+1;j<n;j++)
            {
                temp2 -= (A0[i][j]/A0[i][i])*x[j];
            }
            temp3 = x[i];
            printf("第%d个分量是%lf\n",i+1,x[i]);
            x[i] = relax*(temp1+temp2+A0[i][n]/A0[i][i]-(1-1/relax)*x[i]);
            acc += (x[i] - temp3)*(x[i] - temp3);
        }
        acc = sqrt(acc);
        if(acc<accuracy) break;
    }
    for(i=0;i<n;i++)
    {   
        printf("解向量的第%d个分量为%lf\n",i+1,x[i]);
    }
    printf("总共迭代了%d步\n",k);
   

    return 0;

    
}