#include "Graph.cpp"
#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

void Findpath(int pre[],int v,vector<int> &path)
{
    int d = v;
    while(d != -1)
    {
        path.push_back(d);
        d = pre[d];
    }
}

void ShortPath(ALGraph *G,int u,int v,vector<int> &path)
{
    ArcNode *p;
    int w;
    queue<int> qu;
    int pre[MAXV];
    int visited[MAXV]={0};
    qu.push(u);
    visited[u] = 1;
    pre[u] = -1;
    while(!qu.empty())
    {
        w = qu.front(); qu.pop();
        if (w == v)
        {
            Findpath(pre,v,path);
            return;
        }
        p = G->adjlist[w].firstarc;
        while(p != nullptr )
        {   if (visited[p->adjvex] == 0)
            {
                visited[p->adjvex] = 1;
                qu.push(p->adjvex);
                pre[p->adjvex] = w;
            }
            p = p->nextarc;
        }
    }
}

void Disppath(vector<int> path)
{
    vector<int>::reverse_iterator it;
    for(it = path.rbegin();it!= path.rend();++it)
    {
        printf("%d ",*it);
    }
    printf("\n");
}


int main()
{
    ALGraph *G = new ALGraph;
    int n = 5,e = 7;
    int A[][MAXV] = {
        {0,1,0,0,1},{0,0,1,1,1},{0,0,0,0,0},{0,0,1,0,1},{0,0,0,0,0}
    };
    
    int u = 0,v = 2;
    CreateAdj(G,A,n);
    vector<int> path;
    printf("求解结果\n");
    for (int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            if(i!=j)
            {
                path.clear();
                ShortPath(G,i,j,path);
                if (path.size()>0)
                {
                    printf("从顶点%d到%d的最短路径:",i,j);
                    Disppath(path);
                }
            }
    return 0;
}


