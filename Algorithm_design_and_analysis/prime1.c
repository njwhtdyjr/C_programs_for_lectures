#include <stdio.h>
#include <math.h>

int main(){
    int n,flag = 0,i;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("%d是一个合数",n);
    }
    else{
        printf("%d是一个素数",n);
    }
    return 0;
}