#include <stdio.h>
#include <math.h>
#define N 100

int main(){
    int i,j,k,n,maxn;
    double a[N][N],b[N],x[N],max,c;
    printf("请输入未知元个数：");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        for (j=0;j<n+1;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for (i=0;i<n;i++){
        b[i] = a[i][n];
    }
    //消元过程
    for (i=0;i<n-1;i++){
        maxn = i;
        max = fabs(a[i][i]);
        for(j=i;j<n;j++){
            if(fabs(a[j][i])>max){
                max = fabs(a[j][i]);
                maxn = j;
            }
            
        }
        for(j=i;j<n;j++){
            c = a[i][j];
            a[i][j] = a[maxn][j];
            a[maxn][j] = c;
        }
        c = b[i];
        b[i] = b[maxn];
        b[maxn] = c;

        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                c = 1.0*a[j][i]/a[i][i];
                b[j] = b[j] - c*b[i];
                for (k=i;k<n;k++){
                    a[j][k] = a[j][k] - c*a[i][k];
                 }
            }
        }


    }
    //回代过程
    x[n-1] = b[n-1]/a[n-1][n-1];
    float s;
    for(i=n-2;i>=0;i--){
        s = 0.0;
        for(j=i+1;j<n;j++){
            s += a[i][j]*x[j];
        }
        x[i] = (b[i]-s)/a[i][i];
    }
    for (i=0;i<n;i++){
        printf("x[%d]的值为%lf\n",i,x[i]);
    }
    return 0;
}