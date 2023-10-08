#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
typedef struct item {
    int x;
    int y;
    struct item * next;
} Item;

typedef struct {
    Item * head;
    Item * tail;   
} Queue;


Queue * CreateQueue(void);
void PushQueue(Queue*,int,int);
void PopQueue(Queue*);
bool IsQueueEmpty(Queue*);




int movingCount(int,int,int);
int main(void)
{   
    printf("%d",movingCount(2,3,1));
    return 0;
}

Queue * CreateQueue(void)
{
    Queue * queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void PushQueue(Queue * queue,int x,int y)
{   
    Item * temp;
    temp = (Item *)malloc(sizeof(Item));
    temp->x = x;
    temp->y = y;
    temp->next = NULL;

    if(queue->head==NULL)
    {
        queue->head = queue->tail = temp;
    }
    else
    {
        queue->tail->next = temp;
        queue->tail = temp;
    }
}

void PopQueue(Queue * queue)
{
    Item * temp;
    temp =  queue->head;
    queue->head = queue->head->next;
    free(temp);  
}

bool IsQueueEmpty(Queue* queue)
{
    if(queue->head == NULL)
    {
        return true;
    }
    else return false;
}


//BFS+Queue
int movingCount(int m,int n,int k)
{
    int i,cnt,x,y;
    int ** visited = (int **)malloc(sizeof(int *)*m);
    for(i=0;i<m;i++)
    {
        visited[i] = (int*)malloc(sizeof(int)*n);
        memset(visited[i],0,sizeof(int)*n);
    }
    Queue * queue = CreateQueue();
    PushQueue(queue,0,0);
    visited[0][0] = 1;
    cnt = 1;
    while(!IsQueueEmpty(queue))
    {
        
        for(int j=0;j<4;j++)
        {   
            x = queue->head->x+directions[j][0];
            y = queue->head->y+directions[j][1];
            if(x>=0 && x<n && y>=0 && y<m)
            {
                if(!visited[y][x] && (x/10)+(x%10)+(y/10)+(y%10)<= k)
                {
                    PushQueue(queue,x,y);
                    visited[y][x] = 1;
                    cnt++;
                }
            }
        }
        PopQueue(queue);
    }
    return cnt;
}