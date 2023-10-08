#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#define ERROR 1e-12
#define MAX 100
#define MOD 1000
#define DIV 100


using namespace std;

typedef struct 
{
    double re;
    double im;
} Eigenvalue ;

int max(int i,int j)
{
    return (i>=j)?i:j;
}

int min(int i,int j)
{
    return (i<=j)?i:j;
}
int sgn(double a)
{
    if(a>0) return 1;
    else return -1;
}
void proposed_triangulation(int n,double **A);
void QR_iterate(int n,double **A,int m);
void inversepower(int n,Eigenvalue *eigen,double **A);


int main(void)
{   
    cout<<setiosflags(ios::scientific)<<setprecision(11);

    int n,i,j,k=0;
    printf("请输入要求出所有特征值的矩阵的维数：");
    scanf("%d",&n);
    int m = n-1;
    double A[n][n],back_A[n][n],im;
    printf("请输入矩阵数据:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&A[i][j]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {    
            back_A[i][j] = A[i][j];
        }
    proposed_triangulation(n,(double **)A);
    
    Eigenvalue eigen[n];

    re_eigen:
    if(fabs(A[m][m-1])<=ERROR)
    {   eigen[m].re = A[m][m];
        eigen[m].im = 0;
        m--;
        goto end;
    }
    else goto complex_eigen_or_double_re_eigen;

    end: 
    if(m==0)
    {
        eigen[m].re = A[m][m];
        eigen[m].im = 0;
        goto result;
    }
    else goto re_eigen;
    
    complex_eigen_or_double_re_eigen:
    if(m==1)
    {   im = (-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]);
        if(im>0)
        {
            eigen[m].re = eigen[m-1].re = (A[m-1][m-1]+A[m][m])/2;
            eigen[m].im = sqrt((-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
            eigen[m-1].im = -eigen[m].im;
        }
        else
        {
            eigen[m].re = eigen[m-1].re = (A[m-1][m-1]+A[m][m])/2;
            eigen[m].im = eigen[m-1].im = 0;
            eigen[m].re += sqrt(-(-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
            eigen[m-1].re -= sqrt(-(-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
        }
        goto result;
    }
    else 
    {   
        if(fabs(A[m-1][m-2])<=ERROR)
        {

            im = (-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]);
            if(im>0)
            {
                eigen[m].re = eigen[m-1].re = (A[m-1][m-1]+A[m][m])/2;
                eigen[m].im = sqrt((-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
                eigen[m-1].im = -eigen[m].im;
            }
            else
            {
                eigen[m].re = eigen[m-1].re = (A[m-1][m-1]+A[m][m])/2;
                eigen[m].im = eigen[m-1].im = 0;
                eigen[m].re += sqrt(-(-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
                eigen[m-1].re -= sqrt(-(-pow(A[m-1][m-1],2)-pow(A[m][m],2)+2*A[m][m]*A[m-1][m-1]-4*A[m][m-1]*A[m-1][m]))/2;
            }
            m -= 2;
            goto end;
        }
        else goto compute;
    }

    compute:
    if(k==MAX) goto failure;
    else 
    {   
        QR_iterate(n,(double **)A,m);
        cout << "进行一次QR迭代后的矩阵如下:";
        for(i=0;i<n;i++)
        {   cout << endl;
            for(j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        }
        cout << endl;
        k++;
        goto re_eigen;
    }



    result:
    cout << "实行QR方法后的矩阵如下:";
        for(i=0;i<n;i++)
        {   cout << endl;
            for(j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        }
    cout << endl;
    cout<<"全体特征值如下:"<<endl;
    for(i=0;i<n;i++)
        cout<<"实部为:"<<eigen[i].re<<"   "<<"虚部为:"<<eigen[i].im<<endl;
    inversepower(n,eigen,(double **)back_A);
    goto last;

    failure:
    cout<<"很遗憾未求出所有的特征值!请增加迭代次数!"<<endl;
    cout<<"实行QR方法后的矩阵暂时如下:";
        for(i=0;i<n;i++)
        {   cout<<endl;
            for(j=0;j<n;j++)
            cout<<A[i][j]<<" ";
        }
    cout << endl;
    if(m == n-1)
    cout<<"很遗憾一个特征值也没求出来"<<endl;
    else
    {   cout<<"输出当前已知的特征值如下:"<<endl;
        for(i=m+1;i<n;i++)
            cout<<"实部为:"<<eigen[i].re<<"    "<<"虚部为:"<<eigen[i].im<<endl;
    }
    goto last;

    last:
    printf("总共QR迭代了%d步",k);
    return 0;
}








void proposed_triangulation(int n,double **A)
{
    int i,j,r,flag;
    double c,h,u[n],v[n],p[n],q[n],t,w[n];
    
    for(r=0;r<n-2;r++)
    {   
        for(flag=0,i=r+2;i<n;i++)
        if(*((double *)A+n*i+r)!=0){
            flag=1;break;
        }
        if(flag==0)continue;
        for(i=r+1,c=0;i<n;i++)c+=pow(*((double *)A+n*i+r),2);
        c = -sgn(*((double *)A+n*(r+1)+r))*sqrt(c);
        h = c*(c-*((double *)A+n*(r+1)+r));
        for(i=0;i<r+1;i++) u[i] = 0;u[i] = *((double *)A+n*(r+1)+r) - c;i++;
        for(;i<n;i++)u[i] = *((double *)A+n*i+r);
        for(i=0;i<r+1;i++) v[i] = 0;for(;i<n;i++) v[i] = u[i]/h;
        for(i=0;i<n;i++){p[i]=0;q[i]=0;for(j=r+1;j<n;j++){p[i]+=*((double *)A+n*j+i)*v[j];q[i]+=*((double *)A+n*i+j)*v[j];}}
        for(t=0,i=r+1;i<n;i++)t+=p[i]*v[i];
        for(i=0;i<r+1;i++)w[i]=q[i];for(;i<n;i++)w[i]=q[i]-t*u[i];
        for(i=0;i<r+1;i++)for(j=r+1;j<n;j++)*((double *)A+n*i+j)-=w[i]*u[j];
        for(;i<n;i++)for(j=0;j<r+1;j++)*((double *)A+n*i+j)-=u[i]*p[j];
        for(i=r+1;i<n;i++)
            for(j=r+1;j<n;j++)
            *((double *)A+n*i+j)-=w[i]*u[j]+u[i]*p[j];
    }
    cout << "拟上三角化后的矩阵如下:";
    for(i=0;i<n;i++)
        {   cout << endl;
            for(j=0;j<n;j++)
                cout <<*((double *)A+n*i+j)<<" ";
        }
    cout << endl;
}

void QR_iterate(int n,double **A,int m)
{   
    double B[m+1][m+1],u[m+1],v[m+1],vv[m+1],p[m+1],q[m+1],w[m+1];
    double s,t,c,h;
    s = *((double *)A+n*(m-1)+m-1)+*((double *)A+n*m+m);
    t = (*((double *)A+n*(m-1)+m-1))*(*((double *)A+n*m+m))-*((double *)A+n*m+m-1)*(*((double *)A+n*(m-1)+m));
    int i,j,k,r,flag;

    for(i=0;i<m+1;i++)
    {   for(j=0;j<m+1;j++)
        {
            B[i][j] = 0;
            for(k=max(i-1,0);k<min(j+2,m+1);k++)
            B[i][j]+=*((double *)A+n*i+k)**((double *)A+n*k+j);            
        }
        for(j=max(i-1,0);j<m+1;j++)
        B[i][j]-=s**((double *)A+n*i+j);
        B[i][i]+=t;
    }

    for(r=0;r<m+1;r++)
    {
        for(flag=0,i=r+1;i<m+1;i++)
        if(B[i][r]!=0){
            flag=1;break;
        }
        if(flag==0)continue;
        for(i=r,c=0;i<m+1;i++)c+=pow(B[i][r],2);
        c = -sgn(B[r][r])*sqrt(c);
        h = c*(c-B[r][r]);
        for(i=0;i<r;i++) u[i] = 0;u[i] = B[r][r] - c;i++;
        for(;i<m+1;i++)u[i] = B[i][r];
        for(i=0;i<r;i++) v[i] = 0;for(;i<m+1;i++) v[i] = u[i]/h;
        for(i=0;i<r;i++)vv[i]=0;for(;i<m+1;i++){vv[i]=0;for(j=r;j<m+1;j++)vv[i]+=B[j][i]*v[j];}
        for(i=r;i<m+1;i++)for(j=r;j<m+1;j++)B[i][j]-=u[i]*vv[j];

        for(i=0;i<m+1;i++){p[i]=0;q[i]=0;for(j=r;j<m+1;j++){p[i]+=*((double *)A+n*j+i)*v[j];q[i]+=*((double *)A+n*i+j)*v[j];}}
        for(t=0,i=r;i<m+1;i++)t+=p[i]*v[i];
        for(i=0;i<r;i++)w[i]=q[i];for(;i<m+1;i++)w[i]=q[i]-t*u[i];
        for(i=0;i<r;i++)for(j=r;j<m+1;j++)*((double *)A+n*i+j)-=w[i]*u[j];
        for(;i<m+1;i++)for(j=0;j<r;j++)*((double *)A+n*i+j)-=u[i]*p[j];
        for(i=r;i<m+1;i++)
            for(j=r;j<m+1;j++)
            *((double *)A+n*i+j)-=w[i]*u[j]+u[i]*p[j];
    }
}


void inversepower(int n,Eigenvalue *eigen,double **A)
{
    int m,i,j,k,p,M[n];
    double back_A[n][n],lambda1,lambda2,x[n],u[n],y[n],mod=0;
    double temp1,temp2,s[n],q,temp3;
    

    for(m=0;m<n;m++)
    {   
        if(eigen[m].im == 0)
        {   
            q = fabs(eigen[m].re-eigen[(m+1)==n?m-1:m+1].re);
            p = (m+1)==n?m-1:m+1;//提前给p赋值
            for(j=0;j<n;j++)
            {
                if(m!=j && fabs(eigen[m].re-eigen[j].re)<q)
                {
                    q = fabs(eigen[m].re-eigen[j].re);
                    p = j;
                }
            }
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    back_A[j][k] = *((double *)A+n*j+k);
            temp3 = (0.75)*eigen[m].re+(0.25)*eigen[p].re;
            for(j=0;j<n;j++)
            {
                back_A[j][j] -= temp3;
            }

            //选主元的Doolittle分解
            for(i=0;i<n;i++)
            {   temp1 = 0;
                k = i;
                for(j=i;j<n;j++)
                {   temp2 = 0;
                    for(p=0;p<i;p++)
                    {    
                        temp2 += back_A[j][p]*back_A[p][i];
                    } 
                    s[j] = back_A[j][i] - temp2;
                    if(fabs(s[j])>temp1)
                    {
                        temp1 = fabs(s[j]);
                        k = j;
                    }
                }
                M[i] = k;

                for(p=0;p<n;p++)
                {   temp2 = back_A[i][p];
                    back_A[i][p] = back_A[k][p];
                    back_A[k][p] = temp2;
                }
                temp2 = s[i];
                s[i] = s[k];
                s[k] = temp2;
                
                back_A[i][i] = s[i];
                for(j=i+1;j<n;j++)
                {   temp2 = 0;
                    for(p=0;p<i;p++)
                    {    
                        temp2 += back_A[i][p]*back_A[p][j];
                    }
                    back_A[i][j] = back_A[i][j] - temp2;
                    back_A[j][i] = s[j]/back_A[i][i];
                }
            }
            //随机产生初始向量
            for(i=0;i<n;i++)
            {
                u[i] = ((double)(rand()%MOD))/DIV;
            }
            //
            for(i=0;i<n;i++)
            {
                mod += u[i]*u[i];
            }
            mod = sqrt(mod);
            for(i=0;i<n;i++)
            {
                x[i] = u[i]/mod;
            }
            
            //求Qy_k-1
            for(j=0;j<n-1;j++)
            {   p = M[j];
                temp2 = x[j];
                x[j] = x[p];
                x[p] = temp2;
            }
            //求y,u
            y[0] = x[0];
            for(i=1;i<n;i++)
            {   temp2 = 0;
                for(j=0;j<i;j++)
                    temp2 += back_A[i][j]*y[j];
                y[i] = x[i] - temp2;
            }
            u[n-1] = y[n-1]/back_A[n-1][n-1];
            for(i=n-2;i>-1;i--)
            {   temp2 = 0;
                for(j=i+1;j<n;j++)
                    temp2 += back_A[i][j]*u[j];
                u[i] = (y[i]-temp2)/back_A[i][i];
            }

            for(i=0;i<n;i++)
            {   x[i] = 0;
                for(j=0;j<n;j++)
                {
                    x[i] += u[j] *(i==j? *((double *)A+n*i+j)-temp3:*((double *)A+n*i+j));
                }
            }

            lambda1 = 0;
            for(i=0;i<n;i++)
            {
                lambda1 += x[i] * u[i];
            }

            lambda2 = lambda1;
            
            do
            {
                lambda1 = lambda2;
                
                mod = 0;
                for(i=0;i<n;i++)
                {
                    mod += u[i]*u[i];
                }
                mod = sqrt(mod);
                for(i=0;i<n;i++)
                {
                    x[i] = u[i]/mod;
                }
                //求Qy_k-1
                for(j=0;j<n-1;j++)
                {   p = M[j];
                    temp2 = x[j];
                    x[j] = x[p];
                    x[p] = temp2;
                }
                //求y,u
                y[0] = x[0];
                for(i=1;i<n;i++)
                {   temp2 = 0;
                    for(j=0;j<i;j++)
                        temp2 += back_A[i][j]*y[j];
                    y[i] = x[i] - temp2;
                }
                u[n-1] = y[n-1]/back_A[n-1][n-1];
                for(i=n-2;i>-1;i--)
                {   temp2 = 0;
                    for(j=i+1;j<n;j++)
                        temp2 += back_A[i][j]*u[j];
                    u[i] = (y[i]-temp2)/back_A[i][i];
                }


                for(i=0;i<n;i++)
                {   x[i] = 0;
                    for(j=0;j<n;j++)
                    {
                        x[i] += u[j] * (i==j? *((double *)A+n*i+j)-temp3:*((double *)A+n*i+j));
                    }
                }

                lambda2 = 0;
                for(i=0;i<n;i++)
                {
                    lambda2 += x[i] * u[i];
                }       

            }while(fabs((1/lambda1)-(1/lambda2))/fabs((1/lambda2)) >ERROR);
            cout<<"反幂法计算的特征值结果为"<<1/lambda2+temp3<<endl;
            cout<<"A的相应于实特征值"<<eigen[m].re<<"的特征向量为:"<<endl;
            for(j=0;j<n;j++)
                    cout<<x[j]<<" ";
            cout<<endl;
        } 
    }



}












