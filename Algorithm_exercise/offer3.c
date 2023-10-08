#include <stdio.h>
int findRepeatNumber(int *nums,int numsSize);
int main(void)
{   
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("%d",findRepeatNumber(nums,n));
    return 0;
}

int findRepeatNumber(int *nums,int numsSize)
{   int i;
    int repeat[numsSize];
    for(i=0;i<numsSize;i++)
    {
        repeat[i]=0;
    }
    for(i=0;i<numsSize;i++)
    {
        if(repeat[nums[i]]==0)
        {
            repeat[nums[i]]= 1;
        }
        else break;
    }
    return nums[i];
}
//O(n) O(n)