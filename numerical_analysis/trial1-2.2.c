#include <stdio.h>

int main(){
    double a = 7654321.0f;
    int i;
    for(i = 0;i<5;i++){
        a = a + 0.2f;
    }
    printf("%lf",a);
}