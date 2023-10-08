#include <stdio.h>

int* exchange(int* nums, int numsSize, int* returnSize);

int exchange1(int* nums,int numsSize);
void exchange2(int* nums,int numsSize);

int main(void)
{
    return 0;
}
//冒泡排序思想(效率不够高)
/*int* exchange(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    if (numsSize==0 || numsSize == 1) return nums;
    int cnt=1;  
    for(int j=0;j<numsSize-1 && cnt!=0;j++)
    {   
        cnt=0;
        for(int i=numsSize-1;i>j;i--)
        {
            if((nums[i]%2)!=(nums[i-1]%2) && (nums[i]%2)==1)
            {
                
                int temp = nums[i];
                nums[i] = nums[i-1];
                nums[i-1] = temp;
                cnt++;
            }

        }
    }
    return nums;

}
*/
//划分
/*int exchange1(int* nums,int numsSize)
{   
    if(numsSize!=0 && numsSize !=1)
    {   
        int r=nums[0]%2;
        int i=1,j=numsSize-1;
        while(i<j)
        {
            while(i<j && nums[j]%2 == 0 ) j--;
            while(i<j && nums[i]%2 != 0 ) i++;
            if(i<j)
            {
                int temp=nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        if(r==0)
        {
            int temp=nums[0];
            nums[0] = nums[i];
            nums[i] = temp;
        }
        return i;
    }
    return -1;
}

void exchange2(int* nums,int numsSize)
{   
    int i;
    i = exchange1(nums,numsSize);
    if(i!=-1)
    {
        exchange2(nums,i);
        exchange2(nums+i+1,numsSize-i-1);
    }
}

//快速排序思想
int* exchange(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    exchange2(nums,numsSize);
    return nums; 
}
*/



/*
void exchange1(int* nums,int numsSize)
{   
    if(numsSize!=0 && numsSize !=1)
    {   
        
        int i=0,j=numsSize-1;
        while(i<j)
        {
            while(i<j && nums[j]%2 == 0 ) j--;
            while(i<j && nums[i]%2 != 0 ) i++;
            if(i<j)
            {
                int temp=nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}



//双指针
int* exchange(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    exchange1(nums,numsSize);
    return nums; 
}
*/