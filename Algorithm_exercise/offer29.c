#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);

int main(void)
{
    return 0;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{   
    
    if(matrixSize==0 || matrixColSize[0]==0) 
    {   
        *returnSize=0; 
        return NULL;
    }
    *returnSize=matrixSize*matrixColSize[0];
    int cntj=matrixColSize[0],cnti=matrixSize-1;
    bool rflag=true,dflag=true;
    int i=0,j=-1;
    int *returnlist=(int*)malloc(*returnSize*sizeof(int));
    
    int index = 0;
    while(cntj!=0 || cnti!=0)
    {
        for(int k=0;k<cntj;k++)
        {   
            if(rflag==true) j++;
            else j--;
            returnlist[index] = matrix[i][j];
            index++;
        }
        cntj--;
        if(cntj<0)break;
        rflag = !rflag;
        for(int k=0;k<cnti;k++)
        {
            if(dflag==true) i++;
            else i--;
            returnlist[index] = matrix[i][j];
            index++;
        }
        cnti--;
        if(cnti<0)break;
        dflag = !dflag;

    }
    return returnlist;
}


