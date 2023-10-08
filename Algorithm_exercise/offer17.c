#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* printNumbers(int n, int* returnSize);

int main(void)
{
    return 0;
}

int * printNumbers(int n,int *returnSize)
{
    *returnSize = (int)(pow(10,n)-1);
    int * list = (int*)malloc(*returnSize*sizeof(int));
    for(int i=1;i<=*returnSize;i++)
    {
        list[i-1] = i;
    }
    return list;
}

