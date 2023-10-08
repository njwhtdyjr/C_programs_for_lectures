#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root);
bool isEqual(struct TreeNode * root1,struct TreeNode* root2);
bool isSymmetric(struct TreeNode* root);

int main(void)
{
    return 0;
}

struct TreeNode* mirrorTree(struct TreeNode* root)
{
    if(root==NULL) return NULL;
    struct TreeNode * temp;
    temp = mirrorTree(root->left);
    root->left = mirrorTree(root->right);
    root->right = temp;
    return root;

}


bool isEqual(struct TreeNode * root1,struct TreeNode* root2)
{
    if(root1==NULL && root2!=NULL) return false;
    if(root1!=NULL && root2==NULL) return false;
    if(root1==NULL && root2==NULL) return true;
    if(root1->val==root2->val)
    {
        return isEqual(root1->left,root2->left) && isEqual(root1->right,root2->right);
    }
    else return false;
}

bool isSymmetric(struct TreeNode* root)
{
    if(root==NULL) return true;
    root->left = mirrorTree(root->left);
    return isEqual(root->left,root->right);
}