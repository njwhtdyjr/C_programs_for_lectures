#include <stdio.h>
#include <stdlib.h>
struct ListNode 
{
    int val;
    struct ListNode *next;
};
int * reversePrint(struct ListNode* head,int* returnSize);
int main(void)
{
    /*建立一个链表*/
    return 0;
}
int *reversePrint(struct ListNode* head,int *returnSize)
{   int size=0;
    int i,*array;
    struct ListNode* p = head;
    for(size=0;p!=NULL;size++)
    {p=p->next;}
    array = (int*)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
    {   
        array[i]=head->val;
        head = head->next;
    }
    int temp;
    for(i=0;i<size/2;i++)
    {
        temp = array[i];
        array[i] = array[size-1-i];
        array[size-1-i]=temp;
    }
    *returnSize = size;
    return array;
}
