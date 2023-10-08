#include <stdio.h>

int* intersection(int a[],int b[]){
    if (sizeof(a)/sizeof(a[0]) == 1 && sizeof(b)/sizeof(b[0]) == 1){
        if (a[0] == b[0]){
            return a;
        }else return;
    } 
    int c;

}