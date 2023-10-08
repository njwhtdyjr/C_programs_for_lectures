#include <stdio.h>
#define N 100

int main(){
    int i,j,k,n;
    double a[N][N],b[N],x[N],y[N],c;
    printf("请输入未知元的个数：");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        for (j=0;j<n+1;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for (i=0;i<n;i++){
        b[i] = a[i][n];
    }

    //分解部分
    for (i=1;i<n;i++){
        a[i][0] = a[i][0]/a[0][0];
    }
    for ( i = 1; i <n ; i++)
    {   
        for(j=i;j<n;j++){
            c = 0.0;
            for(k=0;k<=i-1;k++){
                c += a[i][k]*a[k][j];
            }
            a[i][j] = a[i][j] - c;
        }
        for(j=i+1;j<n;j++){
            c = 0.0;
            for (k=0;k<=i-1;k++){
                c += a[j][k]*a[k][i];
            }
            a[j][i] = (a[j][i]-c)/a[i][i];
        }
    

    }
    //求解部分
    y[0] = b[0];
    for (i=1;i<n;i++){
        c = 0.0;
        for(j=0;j<=i-1;j++){
            c += a[i][j]*y[j];
        }
        y[i] = b[i] - c;

    }
    x[n-1] = y[n-1]/a[n-1][n-1];
    for(i=n-2;i>=0;i--){
        c = 0.0;
        for(j=n-1;j>i;j--){
            c += a[i][j]*x[j];
        }
        x[i] = (y[i]-c)/a[i][i];
    }
    for (i=0;i<n;i++){
        printf("x[%d]的值为%lf\n",i,x[i]);
    }
    return 0;
}