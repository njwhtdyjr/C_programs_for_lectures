#include <stdio.h>
#define MOD 1000
#define DIV 100
#include <stdlib.h>
#define MAXSTEP 150
#define accuracy 0.00001
#include <math.h>

int main()
{   int n,i,j,k;
    printf("请输入矩阵的维数:\n");
    scanf("%d",&n);
    double A[n][n+1],x1[n],x2[n],temp,temp1,temp2;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n+1;j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }
    
    for(i=0;i<n;i++)
    {
        x1[i] = ((double)(rand()%MOD))/DIV;
    }
    
    for(k=0;k<MAXSTEP;k++)
    {   
        if(k%2 == 0)
        {
            for(i=0;i<n;i++)
            {   temp = 0;
                for(j=0;j<n;j++)
                {
                    if(j!=i)
                    {
                        temp -= A[i][j] * x1[j]; 
                    }
                }
                x2[i] = (temp+A[i][n])/A[i][i];
                printf("第%d个分量为%lf\n",i+1,x2[i]);

            }
            temp1 = 0;
            temp2 = 0;
            for(i=0;i<n;i++)
            {
                temp1 += (x2[i]-x1[i])*(x2[i]-x1[i]);
                temp2 += x2[i]*x2[i];
            }
            if(sqrt(temp1) <= accuracy) break;
        }else{

            for(i=0;i<n;i++)
            {   temp = 0;
                for(j=0;j<n;j++)
                {
                    if(j!=i)
                    {
                        temp -= A[i][j] * x2[j]; 
                    }
                }
                x1[i] = (temp+A[i][n])/A[i][i];
                printf("第%d个分量为%lf\n",i+1,x1[i]);
            }
            temp1 = 0;
            temp2 = 0;
            for(i=0;i<n;i++)
            {
                temp1 += (x2[i]-x1[i])*(x2[i]-x1[i]);
                temp2 += x1[i]*x1[i];
            }
            if(sqrt(temp1) < accuracy) break;


        }
        

        
    }   
    if(MAXSTEP%2 == 0)
    {
        
        for(i=0;i<n;i++)
        {
            
            printf("解向量的第%d个分量为%lf\n",i+1,x1[i]);
        }
    }else{
        for(i=0;i<n;i++)
        {
            printf("解向量的第%d个分量为%lf\n",i+1,x2[i]);
        }
    }

    temp = sqrt((x1[0]-2)*(x1[0]-2)+(x1[1]-1)*(x1[1]-1)+(x1[2]+1)*(x1[2]+1));
    
    printf("总共迭代了%d步\n",k);
    printf("取2范数的绝对误差:%lf",temp);
    return 0; 
    













}




