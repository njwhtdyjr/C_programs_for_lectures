#define MAXV 100
#define MAXL 100
#include <stdlib.h>

typedef struct ANode
{
    int adjvex;
    int weight;
    struct ANode  *nextarc;
} ArcNode ;
typedef struct Vnode
{
    char data[MAXL];
    ArcNode *firstarc;
} VNode;
typedef VNode AdjList[MAXV];
typedef struct
{
    AdjList adjlist;
    int n,e;
} ALGraph;

void CreateAdj(ALGraph *G,int A[][MAXV],int n)
{   ArcNode *p;
    for(int i = 0;i<n;i++)
    //提前使指针为空指针！！！
    {   G->adjlist[i].firstarc = nullptr;
        for(int j = 0;j<n;j++)
        {    if(A[i][j] == 1)
            {   p= (ArcNode *) malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
                
            }
        }
    }
}

