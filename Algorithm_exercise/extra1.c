#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
    int n;
    scanf("%d",&n);
    int len,letmax,betmax,*t1,*t2,answer[n],i;
    for(i=0;i<n;i++)
    {   
        int j;

        scanf("%d",&len);
        t1 = (int*)malloc(len*sizeof(int));
        t2 = (int*)malloc(len*sizeof(int));
        for(j=0;j<len;j++)scanf("%d",&t1[j]);
        for(j=0;j<len;j++)scanf("%d",&t2[j]);
        if(t1[len-1]<=t2[len-1])
        {letmax = t1[len-1];
         betmax = t2[len-1];   }
        else
        {
            letmax = t2[len-1];
            betmax = t1[len-1];
        }
        for(j=0;j<len-1;j++)
        {   
            if(t1[j]>betmax || t2[j]>betmax)
            {answer[i]=0;break;}
            else if(t1[j]>letmax && t2[j]>letmax)
            {
              answer[i]=0;break;    
            }
        }
        if(j==len-1)
        answer[i]=1;
        
        free(t1);
        free(t2);
    }
    for(i=0;i<n;i++)
    {if(answer[i]==0)printf("NO\n");else printf("YES\n");}

    return 0;
}
