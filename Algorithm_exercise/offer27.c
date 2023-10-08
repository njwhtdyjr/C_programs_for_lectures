#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root);

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