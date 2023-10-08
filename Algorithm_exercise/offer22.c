#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* getKthFromEnd(struct ListNode* head, int k);


int main(void)
{
    return 0;
}

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if(head == NULL) return NULL;
    struct ListNode * temp = head;
    int cnt=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    if(k>cnt) return NULL;
    while(cnt>k)
    {
        head = head->next;
        cnt--;
    }
    return head;

}