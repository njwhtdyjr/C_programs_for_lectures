#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSubStructure_1(struct TreeNode* A, struct TreeNode* B);
bool isSubStructure(struct TreeNode* A, struct TreeNode* B);

int main(void)
{
    return 0;
}

bool isSubStructure_1(struct TreeNode* A, struct TreeNode* B)
{
    if(B==NULL) return true;
    if(A==NULL) return false;
    if(A->val!=B->val) return false;
    return isSubStructure_1(A->left,B->left) && isSubStructure_1(A->right,B->right);
}



bool isSubStructure(struct TreeNode* A, struct TreeNode* B)
{
    if(A==NULL || B==NULL) return false;
    if(A->val==B->val) 
    {
        if(isSubStructure_1(A,B)==true) return true;
        return isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }
    return isSubStructure(A->left,B) || isSubStructure(A->right,B);

}
