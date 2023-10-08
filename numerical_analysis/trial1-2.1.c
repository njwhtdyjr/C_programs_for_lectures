#include <stdio.h>

int main(){
    double pi0 = 3.141592653589793,pi1;
    pi1 = pi0 + 0.000123456789123;
    double ppi0 = 3.1415927;
    double ppi1 = 3.1417161;
    
    printf("绝对误差：%.16lf\n",(pi0-ppi0));
    printf("相对误差：%.16lf\n",(pi0-ppi0)/pi0);
    printf("绝对误差：%.16lf\n",(pi1-ppi1));
    printf("相对误差：%.16lf\n",(pi1-ppi1)/pi1);
    printf("近似值：%.11lf\n",(ppi0-ppi1));
    printf("绝对误差：%.16lf\n",(ppi0-ppi1)+0.000123456789123);
    printf("相对误差：%.16lf\n",((ppi0-ppi1)+0.000123456789123)/0.000123456789123);
    return 0;
}