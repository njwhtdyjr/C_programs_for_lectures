#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct item {
    int value;
    struct item * next;
} Item;

typedef struct {
    Item * head;
} Stack;

Stack* StackCreate() {
    Stack * head = (Stack*)malloc(sizeof(Stack));
    head->head = NULL;
    return head;
}

void StackPush(Stack* obj, int x) {
    if(obj->head==NULL)
    {
        Item * temp = (Item*)malloc(sizeof(Item));
        temp->value = x;
        temp->next = NULL;
        obj->head = temp; 
    }
    else
    {
        Item * temp = (Item*)malloc(sizeof(Item));
        temp->value = x;
        temp->next = obj->head;
        obj->head = temp;
    }
}

void StackPop(Stack* obj) {
    if(obj->head!=NULL)
    {   
        Item * temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
}

int StackTop(Stack* obj) {
    return obj->head->value;
}

void StackFree(Stack* obj) {
    while(obj->head!=NULL)
    {
        StackPop(obj);
    }
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize);

int main(void)
{
    return 0;
}

bool validateStackSequences(int* pushed,int pushedSize,int *popped,int poppedSize)
{   
    if(pushedSize==0 || pushedSize==1 || pushedSize==2) return true;
    Stack * stack = StackCreate();
    int i=0,j=0;
    StackPush(stack,pushed[i]);
    i++;
    while(stack->head!=NULL || i!=pushedSize)
    {
        while(stack->head==NULL || StackTop(stack)!=popped[j])
        {   
            if(i>pushedSize-1) return false;
            StackPush(stack,pushed[i]);
            i++;
        }
        StackPop(stack);
        j++;
    }
    return true;
}




