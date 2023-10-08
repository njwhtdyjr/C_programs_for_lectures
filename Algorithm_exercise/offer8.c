#include <stdio.h>
#include <stdlib.h>
//函数内改变变量值的影响传递至函数外，需要传递待改变值的指针
typedef struct item{
    int value;
    struct item * next;
}Item;

typedef struct {
    Item * push;
    Item * pop;
}CQueue;

Item * CreateStack(void);
void PushStack(Item **head,int value);
int PopStack(Item **head);
CQueue * cQueueCreate(void);
void cQueueAppendTail(CQueue *obj,int value);
int cQueueDeleteHead(CQueue* obj);
void cQueueFree(CQueue* obj);








int main(void)
{
    CQueue * obj;
    obj = cQueueCreate();
    cQueueAppendTail(obj,3);
    printf("%d",cQueueDeleteHead(obj));
    printf("%d",cQueueDeleteHead(obj));
    printf("%d",cQueueDeleteHead(obj));
    return 0;
}
Item * CreateStack(void)
{
    Item * head = NULL;
    return head;
}

void PushStack(Item **head,int value)
{
    Item * temp;
    temp = (Item *)malloc(sizeof(Item));
    temp->value = value;
    temp->next = *head;
    *head = temp;
}
int PopStack(Item **head)
{
    if (*head == NULL) return -1;
    Item * temp;
    int value;
    temp = (*head)->next;
    value = (*head)->value;
    free(*head);
    *head = temp;
    return value;
}
CQueue * cQueueCreate(void)
{
    CQueue * queue;
    queue = (CQueue *)malloc(sizeof(CQueue));
    queue->push = CreateStack();
    queue->pop = CreateStack();
    return queue;
}
void cQueueAppendTail(CQueue *obj,int value)
{
    PushStack(&(obj->push),value);
}
int cQueueDeleteHead(CQueue* obj)
{
    if(obj->pop!=NULL)return PopStack(&(obj->pop));
    while(obj->push!=NULL)
    {
        PushStack(&(obj->pop),PopStack(&(obj->push)));
    }
    return PopStack(&(obj->pop));
}
void cQueueFree(CQueue* obj)
{
    while(obj->push!=NULL)PopStack(&(obj->push));
    while(obj->pop!=NULL)PopStack(&(obj->pop));
    
}











