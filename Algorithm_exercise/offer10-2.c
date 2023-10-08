#include <stdio.h>
int main(void)
{
    return 0;
}
int numWays(int n){
    if(n==0)return 1;
    if(n==1)return 1;
    
    int i,j,k,temp,cnt=2,mod=1000000007;
    i = 1;
    j = 1;
    k = 2;
    while(cnt<n)
    {   
        k = (k+j)%mod;
        temp = (j);
        j = (j+i)%mod;
        i = (temp);
        cnt++;
    }
    return k;
}