#include <stdio.h>
#include <algorithm>
#include <iostream>

int min(int i,int j)
{
    if(i<=j)
    {
        return i;
    }else return j;
}

int max(int i, int j)
{
    if(i<=j)
    {
        return j;
    }else return i;
}
//注意C的第s+1行为C[s],一定要注意从0开始，小心序号，可以调试看看是否序号对齐了
int main()
{   
    int n,r,s,i,j,k;
    printf("请输入矩阵的维数:\n");
    scanf("%d",&n);
    printf("请输入矩阵的上半带宽:\n");
    scanf("%d",&s);
    printf("请输入矩阵的下半带宽:\n");
    scanf("%d",&r);


    //输入数据，以C[r+s+1][n]存储矩阵
    double C[r+s+1][n],b[n],x[n];
    printf("请按列输入矩阵的元素和右端向量的元素！！！\n");
    for(i=0;i<s+1;i++)
    {
        for(j=0;j<r+1+i;j++)
        {
            scanf("%lf",&C[j-i+s][i]);
        }
    }
    for(i=s+1;i<n-r;i++)
    {
        for(j=0;j<r+s+1;j++)
        {
            scanf("%lf",&C[j][i]);
        }
    }
    for(i=n-r;i<n;i++)
    {
        for(j=i-s;j<n;j++)
        {
            scanf("%lf",&C[j-i+s][i]);
        }
    }
    for(i=0;i<n;i++)
    {
            scanf("%lf",&b[i]);
    }



    //带状分解
    for(k=0;k<n;k++)
    {
        for(j=k;j<=min(k+s,n-1);j++)
        {
            for(i=max(max(0,k-r),j-s);i<=k-1;i++)
            {
                C[k-j+s][j] -=  C[k-i+s][i]*C[i-j+s][j];
            }
        }
        for(i=k+1;i<=min(k+r,n-1);i++)
        {
            for(j=max(max(0,i-r),k-s);j<=k-1;j++)
            {
                C[i-k+s][k] -= C[i-j+s][j]*C[j-k+s][k];
            }
            C[i-k+s][k] /= C[s][k];            
        }
        
    }

    //计算解向量
    for(i=1;i<n;i++)
    {
        for(j=max(0,i-r);j<=i-1;j++)
        {
            b[i] -= C[i-j+s][j]*b[j];
        }
    }
    x[n-1] = b[n-1]/C[s][n-1];
    for(i=n-2;i>-1;i--)
    {
        for(j=i+1;j<=min(i+s,n-1);j++)
        {
            b[i] -= C[i-j+s][j]*x[j];
        }
        x[i] = b[i]/C[s][i];
    }

    //输出结果
    for (i=0;i<n;i++)
    {
        printf("x[%d]的值为%lf\n",i,x[i]);
    }

    return 0;

}



