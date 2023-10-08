#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct treequeuenode {
    struct TreeNode * treenode;
    struct treequeuenode * next;
    int level;
} TreeQueueNode;

typedef struct treequeue {
    TreeQueueNode * head;
    TreeQueueNode * tail;
} TreeQueue;

TreeQueue * CreateQueue(void);
void PushQueue(TreeQueue * queue,struct TreeNode * treenode);
int PopQueue(TreeQueue * queue);
int** levelOrder(struct TreeNode* root, int* returnSize,int** returnColumnSizes);

int main(void)
{
    return 0;
}

TreeQueue * CreateQueue(void)
{
    TreeQueue * queue = (TreeQueue *)malloc(sizeof(TreeQueue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void PushQueue(TreeQueue * queue,struct TreeNode * treenode)
{   
    if(treenode!= NULL)
    {
        TreeQueueNode * temp = (TreeQueueNode *)malloc(sizeof(TreeQueueNode));
        temp->treenode = treenode;
        temp->next = NULL;
        if(queue->head==NULL) 
        {   
            queue->head = temp;
            queue->tail = temp;
            temp->level = 0;
        }
        else
        {
            queue->tail->next = temp;
            queue->tail = temp;
            temp->level = queue->head->level+1;
        }
    }
}

int PopQueue(TreeQueue * queue)
{
    int tempvalue;
    TreeQueueNode * temp;
    temp = queue->head;
    queue->head = temp->next;
    tempvalue = temp->treenode->val;
    free(temp);
    return tempvalue;
}



int** levelOrder(struct TreeNode* root, int* returnSize,int** returnColumnSizes)
{   
    if(root == NULL){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return returnColumnSizes;
    }
    int cnt=0,levelk=-1;
    int** value = (int **)malloc(1000*sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000*sizeof(int));
    TreeQueue * queue = CreateQueue();
    PushQueue(queue,root);
    (*returnColumnSizes)[0] = 1; 
    
    while(queue->head!=NULL)
    {   
        cnt = 0;
        int *temp = (int*)malloc(1000*sizeof(int));
        while(queue->head != NULL && queue->head->level==levelk+1)
        {
            
            PushQueue(queue,queue->head->treenode->left);
            PushQueue(queue,queue->head->treenode->right);
            temp[cnt] = PopQueue(queue);
            cnt++;
        }
        levelk++;
        (*returnColumnSizes)[levelk] = cnt;
        value[levelk] = (int*)malloc(cnt*sizeof(int));
        if(levelk%2==0)
        {
            for(int i=0;i<cnt;i++)
            {
                value[levelk][i] = temp[i];
            }
            free(temp);
        }
        else
        {
            for(int i=0;i<cnt;i++)
            {
                value[levelk][cnt-1-i] = temp[i];
            }
            free(temp);
        }
    }
    *returnSize = levelk+1;
    return value;
    
}









