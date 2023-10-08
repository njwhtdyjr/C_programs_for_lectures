#include <stdio.h>
#include <math.h>

int sgn(double a)
{
    if(a>0) return 1;
    else return -1;
}

int main(void)
{
    int n,i,j,r,flag;
    printf("请输入待QR分解矩阵的维数:");
    scanf("%d",&n);
    double A[n][n],c,h,Q[n][n],u[n],v[n],w[n],p[n];
    printf("请输入矩阵数据:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&A[i][j]);
    for(i=0;i<n;i++)for(j=0;j<n;j++){if (i==j)Q[i][j]=1;else Q[i][j]=0;}
    for(r=0;r<n-1;r++)
    {
        for(flag=0,i=r+1;i<n;i++)
        if(A[i][r]!=0){
            flag=1;break;
        }
        if(flag==0)continue;
        for(i=r,c=0;i<n;i++)c+=pow(A[i][r],2);
        c = -sgn(A[r][r])*sqrt(c);
        h = c*(c-A[r][r]);
        for(i=0;i<r;i++) u[i] = 0;u[i] = A[r][r] - c;i++;
        for(;i<n;i++)u[i] = A[i][r];
        for(i=0;i<r;i++) v[i] = 0;for(;i<n;i++) v[i] = u[i]/h;
        for(i=0;i<n;i++){w[i]=0;for(j=r;j<n;j++){w[i]+=Q[i][j]*u[j];}}
        for(i=0;i<n;i++)for(j=r;j<n;j++)Q[i][j]-=w[i]*v[j];
        for(i=0;i<r;i++)p[i]=0;for(;i<n;i++){p[i]=0;for(j=r;j<n;j++)p[i]+=A[j][i]*v[j];}
        for(i=r;i<n;i++)for(j=r;j<n;j++)A[i][j]-=u[i]*p[j];
    }
    printf("QR分解后的上三角矩阵如下:");
    for(i=0;i<n;i++)
        {printf("\n");
            for(j=0;j<n;j++)
                printf("%f ",A[i][j]);}
    printf("\nQR分解后的正交矩阵如下:");
    for(i=0;i<n;i++)
        {printf("\n");
            for(j=0;j<n;j++)
                printf("%f ",Q[i][j]);}




    return 0;
}