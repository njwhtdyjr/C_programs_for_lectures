#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);

int main(void)
{
    return 0;
}

struct ListNode* reverseList(struct ListNode* head)
{   
    if(head==NULL || head->next==NULL)return head;
    struct ListNode * temp1,*temp2,*temp;
    temp1 = head->next;
    temp2 = temp1->next;
    temp1->next = head;
    head->next = NULL;
    while(temp2!=NULL)
    {   
        
        temp = temp1;
        temp1 = temp2;
        temp2 = temp2->next;
        temp1->next = temp;
    }
    return temp1;

    
}