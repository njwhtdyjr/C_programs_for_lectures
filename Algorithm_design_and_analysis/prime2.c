#include <stdio.h>
#include <math.h>

int main(){
    int n,i,max,k;
    printf("请输入一个正整数：");
    scanf("%d",&n);
    max = n;
    int a[n-1],j;
    for (i=0;i<n-1;i++){
        a[i] = i+2;
    }
    
    i = 2;
    while (i*i <= max){
        j = i;
       
        while(i*j<max){
            a[i*j-2] = 0;
            j += 1;
        }

        if(i*j == max) 
        {
            a[i*j-2] = 0;
            j = 1;
            
            while (a[max-2-j]==0){
                j += 1;
            }
            max = a[max-2-j];
        }

        do{
            i += 1;            
        }
        while (a[i-2] == 0);
       
    }
    
    
    if (a[n-2] == 0){
        printf("%d是一个合数",n);
    }
    else{
        printf("%d是一个素数",n);

    }
    return 0;
}