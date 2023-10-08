#include <stdio.h>
#include <stdint.h>
#include <math.h>

int hammingWeight(uint32_t n);


int main(void)
{   
    uint32_t n;
    scanf("%d",&n);
    printf("%d",hammingWeight(n));
    return 0;
}

int hammingWeight(uint32_t n)
{
    int mod;
    int cnt=0;
    if((n & (uint32_t)(pow(2,0)))%2) cnt++;
    for(int i = 1;i<32;i++)
    {
        mod = (n & (uint32_t)(pow(2,i))) / 2;
        if(mod) cnt++;   
    }
    return cnt;
}