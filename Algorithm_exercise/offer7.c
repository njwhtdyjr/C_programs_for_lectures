#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

int main(void)
{

    return 0;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{   
    int i,j;
    if(preorderSize==0)return NULL;
    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    if(preorderSize==1)return root;
    int leftsize=0,rightsize=0;
    for(j=0;;j++){

        if(inorder[j]==root->val)
        break;        
        leftsize ++;
    }
    rightsize = preorderSize-leftsize-1;
    root->left = buildTree(preorder+1,leftsize,inorder,leftsize);
    root->right = buildTree(preorder+leftsize+1,rightsize,inorder+j+1,rightsize); 
    return root;
}