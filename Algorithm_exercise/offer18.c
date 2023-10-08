#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int main(void)
{
    return 0;
}

struct ListNode* deleteNode(struct ListNode* head, int val){
    
    struct ListNode * temp = head;
    
    if(temp->val==val)
    {
        return head->next;
    }
    
    while(temp->next!=NULL && temp->next->val!=val)
    {
        temp = temp->next;
    }
    
    if(temp->next!=NULL)
    {
        temp->next = temp->next->next;
    }
    
    return head;



}
