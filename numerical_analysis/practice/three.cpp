#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#define ERROR 1e-12



void newton(double x,double y,double * ut);
double interpolate(double u,double t);
double least_square(double *z[11],int k);
double xyinterpolate(double x,double y,double *z[11]); 

using namespace std;
int main(void)
{   
    double *z[11];
    double p[2],error;
    for(int i=0;i<11;i++)
    {
        z[i] = (double *)malloc(21*sizeof(double));
    }
    
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<21;j++)
        {
          newton(0.08*i,0.5+0.05*j,p);
          z[i][j] = interpolate(p[0],p[1]);
        }
    }

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<21;j++)
        {
          cout<<"x:"<<setiosflags(ios::scientific)<<setprecision(2)<<0.08*i<<"  ";
          cout<<"y:"<<setiosflags(ios::scientific)<<setprecision(3)<<0.5+0.05*j<<"  ";   
          cout<<"z:"<<setiosflags(ios::scientific)<<setprecision(12) << z[i][j] << endl;  
        }
    }

    
    int k=1;
    do{
        error = least_square(z,k);
        k++;
    }while(error>1e-7);
    
    return 0;
}

void newton(double x,double y,double * ut)
{
    
    double solution[4]={1,1,1,1};
    double deltasolution[4];
    //采用列主元素高斯消元法
    double b[4];
    
    double max1=0,max2=0;
    do
    {   
        double A[4][4]={{1,-0.5*sin(solution[1]),1,1},{0.5*cos(solution[0]),1,1,1},{1,0.5,-sin(solution[2]),1},{0.5,1,1,cos(solution[3])}};
        b[0]=-(0.5*cos(solution[1])+solution[0]+solution[2]+solution[3]-x-2.67);
        b[1]=-(solution[1]+0.5*sin(solution[0])+solution[2]+solution[3]-y-1.07);
        b[2]=-(0.5*solution[1]+solution[0]+cos(solution[2])+solution[3]-x-3.74);
        b[3]=-(solution[1]+0.5*solution[0]+solution[2]+sin(solution[3])-y-0.79);
        int maxn;
        double max,c;
        //消元过程
        for (int i=0;i<3;i++)
        {
            maxn = i;
            max = fabs(A[i][i]);
            for(int j=i;j<4;j++){
                if(fabs(A[j][i])>max){
                    max = fabs(A[j][i]);
                    maxn = j;
                }
                
            }
            for(int j=i;j<4;j++){
                c = A[i][j];
                A[i][j] = A[maxn][j];
                A[maxn][j] = c;
            }
            c = b[i];
            b[i] = b[maxn];
            b[maxn] = c;

            for(i=0;i<3;i++){
                for(int j=i+1;j<4;j++){
                    c = 1.0*A[j][i]/A[i][i];
                    b[j] = b[j] - c*b[i];
                    for (int k=i;k<4;k++){
                        A[j][k] = A[j][k] - c*A[i][k];
                    }
                }
            }
        }
        //回代过程
        deltasolution[3] = b[3]/A[3][3];
        double s;
        for(int i=2;i>=0;i--){
            s = 0.0;
            for(int j=i+1;j<4;j++){
                s += A[i][j]*deltasolution[j];
            }
            deltasolution[i] = (b[i]-s)/A[i][i];
        }
        for(int i=0;i<4;i++) solution[i] += deltasolution[i];
        max1 = max2 = 0;
        for(int i=0;i<4;i++)
        {
            if(fabs(deltasolution[i])>max1) max1 = fabs(deltasolution[i]);
            if(fabs(solution[i])>max2) max2 = fabs(solution[i]);
        } 
    }while(max1/max2>ERROR);
    ut[0] = solution[0];ut[1] = solution[1];
}


double interpolate(double u,double t)
{
    double mod,times;
    int i,j;
    mod = fmod(u,0.4);
    times = (u-mod)/0.4;
    if(mod<=0.2) i = (int)times;
    else i=(int)(times+1);
    mod = fmod(t,0.2);
    times = (t-mod)/0.2;
    if(mod<=0.1) j = (int)times;
    else j = (int)(times+1);
    if(i==0) i++; if(i==5) i--;
    if(j==0) j++; if(j==5) j--;
    
    double f[6][6] = {
    {-0.5,-0.34,0.14,0.94,2.06,3.5},
    {-0.42,-0.5,-0.26,0.3,1.18,2.38},
    {-0.18,-0.5,-0.5,-0.18,0.46,1.42},
    {0.22,-0.34,-0.58,-0.5,-0.1,0.62},
    {0.78,-0.02,-0.5,-0.66,-0.5,-0.02},
    {1.5,0.46,-0.26,-0.66,-0.74,-0.5}
    };
    double temp,result=0;
    for(int k=0;k<3;k++)
    {   
        for(int m=0;m<3;m++)
        {
            temp = 1;
            for(int l=0;l<3;l++)
            {   
                if(k!=l)
                {
                    temp *= (u-0.4*(i+l-1))/(0.4*(k+i-1)-0.4*(i+l-1));      
                }
            }
            for(int l=0;l<3;l++)
            {
                if(m!=l)
                {
                    temp *= (t-0.2*(j+l-1))/(0.2*(m+j-1)-0.2*(j+l-1));
                }
            }
            temp *= f[m+j-1][k+i-1];
            result += temp;
        }
    }
    return result;
}



double xyinterpolate(double x,double y,double *z[11])
{
    double mod,times;
    int i,j;
    mod = fmod(x,0.08);
    times = (x-mod)/0.08;
    if(mod<=0.04) i = (int)times;
    else i=(int)(times+1);
    mod = fmod(y-0.5,0.05);
    times = (y-0.5-mod)/0.05;
    if(mod<=0.025) j = (int)times;
    else j = (int)(times+1);
    if(i==0) i++; if(i==10) i--;
    if(j==0) j++; if(j==20) j--;
    
    double temp,result=0;
    for(int k=0;k<3;k++)
    {   
        for(int m=0;m<3;m++)
        {
            temp = 1;
            for(int l=0;l<3;l++)
            {   
                if(k!=l)
                {
                    temp *= (x-0.08*(i+l-1))/(0.08*(k+i-1)-0.08*(i+l-1));      
                }
            }
            for(int l=0;l<3;l++)
            {
                if(m!=l)
                {
                    temp *= (y-(0.5+0.05*(j+l-1)))/((0.5+0.05*(m+j-1))-(0.5+0.05*(j+l-1)));
                }
            }
            temp *= z[k+i-1][m+j-1];
            result += temp;
        }
    }
    return result;
}


double least_square(double *z[11],int k)
{
    double C[k+1][k+1];
    double A[k+1][21],D[k+1][21];
    double B[11][k+1],BTB[k+1][k+1];
    double BTu[k+1];
    double G[21][k+1],GTG[k+1][k+1];
    double GTu[k+1];





    for(int i=0;i<11;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            B[i][j]= pow(0.08*i,j);
        }
    }
    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            BTB[i][j]=0;
            for(int l=0;l<11;l++)
            {
                BTB[i][j]+=B[l][i]*B[l][j];
            }
        }
    }
    int l,M[k+1];
    double temp1,temp2,s[k+1];
    //三角分解
    for(int i=0;i<k+1;i++)
    {   temp1 = 0;
        l = i;
        for(int j=i;j<k+1;j++)
        {   temp2 = 0;
            for(int p=0;p<i;p++)
            {    
                temp2 += BTB[j][p]*BTB[p][i];
            } 
            s[j] = BTB[j][i] - temp2;
            if(fabs(s[j])>temp1)
            {
                temp1 = fabs(s[j]);
                l = j;
            }
        }
        M[i] = l;

        for(int p=0;p<k+1;p++)
        {   
            temp2 = BTB[i][p];
            BTB[i][p] = BTB[l][p];
            BTB[l][p] = temp2;
        }
        temp2 = s[i];
        s[i] = s[l];
        s[l] = temp2;
        
        BTB[i][i] = s[i];
        for(int j=i+1;j<k+1;j++)
        {   
            temp2 = 0;
            for(int p=0;p<i;p++)
            {    
                temp2 += BTB[i][p]*BTB[p][j];
            }
            BTB[i][j] = BTB[i][j] - temp2;
            BTB[j][i] = s[j]/BTB[i][i];
        }
    }




    int p;
    double y[k+1];
    for(int j=0;j<21;j++)
    {
        for(int i=0;i<k+1;i++)
        {
            BTu[i]=0;
            for(int l=0;l<11;l++)
            {
                BTu[i]+=B[l][i]*z[l][j];
            }
        }
        for(int i=0;i<k;i++)
        {   p = M[i];
            temp2 = BTu[i];
            BTu[i] = BTu[p];
            BTu[p] = temp2;
        }

        y[0] = BTu[0];
        for(int i=1;i<k+1;i++)
        {   
            temp2 = 0;
            for(int l=0;l<i;l++)
                temp2 += BTB[i][l]*y[l];
            y[i] = BTu[i] - temp2;
        }
        A[k][j] = y[k]/BTB[k][k];
        for(int i=k-1;i>-1;i--)
        {   temp2 = 0;
            for(int l=i+1;l<k+1;l++)
                temp2 += BTB[i][l]*A[l][j];
            A[i][j] = (y[i]-temp2)/BTB[i][i];
        }
    }



    for(int i=0;i<21;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            G[i][j]= pow(0.5+0.05*i,j);
        }
    }

    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            GTG[i][j]=0;
            for(int l=0;l<21;l++)
            {
                GTG[i][j]+=G[l][i]*G[l][j];
            }
        }
    }
    for(int i=0;i<k+1;i++)
    {   temp1 = 0;
        l = i;
        for(int j=i;j<k+1;j++)
        {   
            temp2 = 0;
            for(p=0;p<i;p++)
            {    
                temp2 += GTG[j][p]*GTG[p][i];
            } 
            s[j] = GTG[j][i] - temp2;
            if(fabs(s[j])>temp1)
            {
                temp1 = fabs(s[j]);
                l = j;
            }
        }
        M[i] = l;

        for(p=0;p<k+1;p++)
        {   
            temp2 = GTG[i][p];
            GTG[i][p] = GTG[l][p];
            GTG[l][p] = temp2;
        }
        temp2 = s[i];
        s[i] = s[l];
        s[l] = temp2;
        
        GTG[i][i] = s[i];
        for(int j=i+1;j<k+1;j++)
        {   
            temp2 = 0;
            for(p=0;p<i;p++)
            {    
                temp2 += GTG[i][p]*GTG[p][j];
            }
            GTG[i][j] = GTG[i][j] - temp2;
            GTG[j][i] = s[j]/GTG[i][i];
        }

    }

    for(int j=0;j<21;j++)
    {   
        for(int i=0;i<k+1;i++)
        {
            GTu[i]=G[j][i];
        }

        for(int i=0;i<k;i++)
        {   p = M[i];
            temp2 = GTu[i];
            GTu[i] = GTu[p];
            GTu[p] = temp2;
        }

        y[0] = GTu[0];
        for(int i=1;i<k+1;i++)
        {   
            temp2 = 0;
            for(int l=0;l<i;l++)
                temp2 += GTG[i][l]*y[l];
            y[i] = GTu[i] - temp2;
        }
        D[k][j] = y[k]/GTG[k][k];
        for(int i=k-1;i>-1;i--)
        {   temp2 = 0;
            for(int l=i+1;l<k+1;l++)
                temp2 += GTG[i][l]*D[l][j];
            D[i][j] = (y[i]-temp2)/GTG[i][i];
        }

    }

    for(int i=0;i<k+1;i++)
    {
        for(int j=0;j<k+1;j++)
        {
            C[i][j]=0;
            for(int l=0;l<21;l++)
            {
                C[i][j]+= A[i][l]*D[j][l];
            }
        }
    }

    double error=0,value;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<21;j++)
        {   
            value = 0;
            for(int l=0;l<k+1;l++)
            {
                for(int m=0;m<k+1;m++)
                {
                    value+= C[l][m]*pow(0.08*i,l)*pow(0.5+0.05*j,m);
                }
            }
            error += pow(z[i][j]-value,2);
        }
    }
    cout <<"k:"<< k << "    ";
    cout << "error:"<<setiosflags(ios::scientific)<<setprecision(12)<<error << endl;
    if(error<=1e-7)
    {   
        double p1[2];
        cout<<"满足精度时系数如下:"<<endl;
        for(int i=0;i<k+1;i++)
        {
            for(int j=0;j<k+1;j++)
            {
                cout<<setiosflags(ios::scientific)<<setprecision(12)<<C[i][j]<<"    ";
            }
            cout<<endl;
        }

        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=5;j++)
            {
                cout<<"x:"<<setiosflags(ios::scientific)<<setprecision(2)<<0.1*i<<" ";
                cout<<"y:"<<setiosflags(ios::scientific)<<setprecision(2)<<0.5+0.2*j<<" ";
                cout<<"z:"<<setiosflags(ios::scientific)<<setprecision(12)<<xyinterpolate(0.1*i,0.5+0.2*j,z)<<" ";
               
                value = 0;
                for(int l=0;l<k+1;l++)
                {
                    for(int m=0;m<k+1;m++)
                    {
                        value+= C[l][m]*pow(0.1*i,l)*pow(0.5+0.2*j,m);
                    }
                }
                cout<<"p:"<<setiosflags(ios::scientific)<<setprecision(12)<<value<<"    ";
                newton(0.1*i,0.5+0.2*j,p1);
                cout<<"z:"<<setiosflags(ios::scientific)<<setprecision(12)<<interpolate(p1[0],p1[1])<<" ";
                cout<<endl;
            }
            
        }
    }
    


    return error;
}