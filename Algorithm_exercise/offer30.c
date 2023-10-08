#include <stdio.h>
#include <stdlib.h>

typedef struct item {
    int value;
    int minvalue;
    struct item * next;
} Item;

typedef struct {
    Item * head;
} MinStack;

MinStack* minStackCreate() {
    MinStack * head = (MinStack*)malloc(sizeof(MinStack));
    head->head = NULL;
    return head;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->head==NULL)
    {
        Item * temp = (Item*)malloc(sizeof(Item));
        temp->minvalue = x;
        temp->value = x;
        temp->next = NULL;
        obj->head = temp; 
    }
    else
    {
        Item * temp = (Item*)malloc(sizeof(Item));
        temp->value = x;
        if(x<obj->head->minvalue) temp->minvalue = x;
        else temp->minvalue = obj->head->minvalue;
        temp->next = obj->head;
        obj->head = temp;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->head!=NULL)
    {   
        Item * temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
}

int minStackTop(MinStack* obj) {
    return obj->head->value;
}

int minStackMin(MinStack* obj) {
    return obj->head->minvalue;
}

void minStackFree(MinStack* obj) {
    while(obj->head!=NULL)
    {
        minStackPop(obj);
    }
}


int main(void)
{
    return 0;
}