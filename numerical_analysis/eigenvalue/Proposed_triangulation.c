#include <stdio.h>
#include <math.h>

//内层for循环一定要注意循环变量要初始化；否则可能内层循环只循环了一套！！！
int sgn(double a)
{
    if(a>0) return 1;
    else return -1;
}


int main(void)
{
    int n,i,j,r,flag;
    printf("请输入待拟上三角化矩阵的维数：");
    scanf("%d",&n);
    double A[n][n],c,h,u[n],v[n],p[n],q[n],t,w[n];
    printf("请输入矩阵数据:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&A[i][j]);
    for(r=0;r<n-2;r++)
    {
        for(flag=0,i=r+2;i<n;i++)
        if(A[i][r]!=0){
            flag=1;break;
        }
        if(flag==0)continue;
        for(i=r+1,c=0;i<n;i++)c+=pow(A[i][r],2);
        c = -sgn(A[r+1][r])*sqrt(c);
        h = c*(c-A[r+1][r]);
        for(i=0;i<r+1;i++) u[i] = 0;u[i] = A[r+1][r] - c;i++;
        for(;i<n;i++)u[i] = A[i][r];
        for(i=0;i<r+1;i++) v[i] = 0;for(;i<n;i++) v[i] = u[i]/h;
        for(i=0;i<n;i++){p[i]=0;q[i]=0;for(j=r+1;j<n;j++){p[i]+=A[j][i]*v[j];q[i]+=A[i][j]*v[j];}}
        for(t=0,i=r+1;i<n;i++)t+=p[i]*v[i];
        for(i=0;i<r+1;i++)w[i]=q[i];for(;i<n;i++)w[i]=q[i]-t*u[i];
        for(i=0;i<r+1;i++)for(j=r+1;j<n;j++)A[i][j]-=w[i]*u[j];
        for(;i<n;i++)for(j=0;j<r+1;j++)A[i][j]-=u[i]*p[j];
        for(i=r+1;i<n;i++)
            for(j=r+1;j<n;j++)
            A[i][j]-=w[i]*u[j]+u[i]*p[j];
    }
    printf("拟上三角化后的矩阵如下:");
    for(i=0;i<n;i++)
        {printf("\n");
            for(j=0;j<n;j++)
                printf("%f ",A[i][j]);}
    return 0;
}




















