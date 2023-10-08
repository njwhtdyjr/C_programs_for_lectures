#include <stdio.h>
#include <math.h>
int cuttingRope(int);
int main(void)
{   
    int n;
    scanf("%d",&n);
    printf("%d",cuttingRope(n));
    return 0;
}



int cuttingRope(int n)
{   
    int mod = 1000000007;
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 4;
    if(n==5) return 6;
    if(n==6) return 9;  
    int t,r;
    long long cnt = 1;
    t = n/3;
    r = n%3;
    if(r==0)
    {
        int t1 = t/20,r1 = t%20;
        for(int i = 0;i<t1;i++)
        {
            cnt = (cnt*(((long long)(pow(3,20)))%mod))%mod;
        }
        cnt = (cnt*(((long long)(pow(3,r1)))%mod))%mod;
    }
    else if(r==2)
    {
        int t1 = t/20,r1 = t%20;
        for(int i = 0;i<t1;i++)
        {
            cnt = (cnt*(((long long)(pow(3,20)))%mod))%mod;
        }
        cnt = (cnt*(((long long)(pow(3,r1)))%mod))%mod;
        cnt = (cnt*2)%mod;
    }
    else
    {
        int t1 = (t-1)/20,r1 = (t-1)%20;
        for(int i = 0;i<t1;i++)
        {
            cnt = (cnt*(((long long)(pow(3,20)))%mod))%mod;
        }
        cnt = (cnt*(((long long)(pow(3,r1)))%mod))%mod;
        cnt = (cnt*4)%mod;
    } 
    return cnt;
}