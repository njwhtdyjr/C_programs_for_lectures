#include <stdio.h>
#include <math.h>
int main(){
    int i;
    double num1=0.12346845,num2=0.1235;
    for(i=0;i<4;i++){
        printf("绝对误差：%.16lf\n",(num1-num2)/pow(10,i));
        printf("相对误差：%.16lf\n",(num1-num2)/num1);
    }
    return 0;
}