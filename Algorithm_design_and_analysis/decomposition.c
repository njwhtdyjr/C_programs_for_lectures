#include <stdio.h>
int decomposition(int n)
{   int i,p=0;
    for(i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
           p += decomposition(n/i);
        }
    }
    p++;
    return p;
}
int main()
{
    int n,p;
    printf("请输入要求分解式个数的数:\n");
    scanf("%d",&n);
    p = decomposition(n);
    printf("%d的分解式的个数为%d\n",n,p);
    return 0;
}