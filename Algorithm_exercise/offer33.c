#include <stdio.h>
#include <stdbool.h>

bool verifyPostorder(int* postorder, int postorderSize);


int main(void)
{
    return 0;
}

bool verifyPostorder(int* postorder, int postorderSize)
{
    if(postorderSize<=2) return true;
    int i;
    for(i=postorderSize-2;i>=0 && postorder[i]>postorder[postorderSize-1];i--) continue;
    for(int j=0;j<i;j++)
    {
        if(postorder[j]>postorder[postorderSize-1]) return false;
    }
    return verifyPostorder(postorder,i+1) && verifyPostorder(postorder+i+1,postorderSize-i-2);
}