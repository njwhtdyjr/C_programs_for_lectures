#include <stdio.h>
int fib(int);

int main(void)
{
    return 0;
}


int fib(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    int i,j,k,temp,cnt=2;
    i = 0;
    j = 1;
    k = 1;
    while(cnt<n)
    {   
        k = (k+j)%(1000000007);
        temp = (j);
        j = (j+i)%(1000000007);
        i = (temp);
        cnt++;
    }
    return k;
}