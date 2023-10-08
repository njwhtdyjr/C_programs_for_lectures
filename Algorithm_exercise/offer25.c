#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

int main(void)
{
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct  ListNode * temp1,* temp2,*temp;
    
    if(l1->val>l2->val)
    {   
        temp = l2;
    }
    else
    {   
        temp = l1;
    }

    while(l1!= NULL && l2!= NULL)
    {
        if(l1->val>l2->val)
        { 
            while(l2->next != NULL && l1->val>l2->next->val ) l2 = l2->next;
            temp2 = l2->next;
            l2->next = l1;
            l2 = temp2;
        }
        else
        {   
            while(l1->next != NULL  && l1->next->val<=l2->val) l1 = l1->next;
            temp1 = l1->next;
            l1->next = l2;
            l1 = temp1;
        }
    }
    return temp;


}