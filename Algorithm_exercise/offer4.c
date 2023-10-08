#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool findNumberIn2DArray(int ** matrix,int matrixSize,int *matrixColSize,int target);
int main(void)
{   
    
    int matrixSize;
    scanf("%d",&matrixSize);
    int *matrix[matrixSize],matrixColSize[matrixSize];
    int target,matrixcolsize;
    scanf("%d",&matrixcolsize);
    scanf("%d",&target);
    int i,j;
    for(i=0;i<matrixSize;i++)
    matrixColSize[i]=matrixcolsize;
    for(i=0;i<matrixSize;i++)
    {
        matrix[i] = (int*)malloc(matrixcolsize*sizeof(int));
        for(j=0;j<matrixcolsize;j++)
        scanf("%d",&matrix[i][j]);
    }
    if(findNumberIn2DArray(matrix,matrixSize,matrixColSize,target))
    printf("true");
    else printf("false");
    for(i=0;i<matrixSize;i++)
    {
        free(matrix[i]);
    }

    return 0;
}


bool findNumberIn2DArray(int ** matrix,int matrixSize,int *matrixColSize,int target)
{
    int row=matrixSize-1,col=0;
    if(matrixSize==0)return false;
    if(matrixColSize[0]==0)return false;
    while(matrix[row][col]!=target)
    {
        if(matrix[row][col]>target)
        {
            row -=1;
            if(row==-1) return false;
        }
        else 
        {        
            col+=1;
            if(col==matrixColSize[0])return false;
        }    
    }
    return true;
}