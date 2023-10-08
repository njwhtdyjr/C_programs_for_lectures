#include <stdio.h>
#include <stdbool.h>

int main(void)
{   
    int G[23][23]={{[1]=1,[3]=1,[4]=1}
    ,{[0]=1},
    {[3]=1,[6]=1,[7]=1,[8]=1},
    {[0]=1,[2]=1,[4]=1,[8]=1,[15]=1},
    {[0]=1,[3]=1,[9]=1},
    {[6]=1},
    {[5]=1,[2]=1,[7]=1,[13]=1},
    {[2]=1,[6]=1,[8]=1,[13]=1,[14]=1},
    {[2]=1,[3]=1,[7]=1,[14]=1},
    {[4]=1,[15]=1,[16]=1},
    {[16]=1},
    {[12]=1},
    {[11]=1,[13]=1,[18]=1},
    {[6]=1,[7]=1,[12]=1,[19]=1},
    {[7]=1,[8]=1,[19]=1,[20]=1},
    {[3]=1,[9]=1,[20]=1,[22]=1},
    {[9]=1,[10]=1,[22]=1},
    {[18]=1},
    {[17]=1,[12]=1,[19]=1},
    {[18]=1,[13]=1,[14]=1,[20]=1},
    {[19]=1,[14]=1,[15]=1,[21]=1},
    {[20]=1,[22]=1},
    {[21]=1,[15]=1,[16]=1}
    };
    int edge=35;
    int coververtex[23];
    int num=0;
    
    
    bool flag = true;
    int E[23]={3,1,4,5,3,1,4,5,4,3,1,1,3,4,4,4,3,1,3,4,4,2,3};
    while(edge!=0)
    {   
        while(true)
        {   
            flag = true;
            for(int i=0;i<23;i++)
            {
                if(E[i]==1)
                {   
                    flag = false;
                    for(int j=0;j<23;j++)
                    {
                        if(G[i][j]==1)
                        {
                            coververtex[num]=j+1;
                            num++;
                            for(int k=0;k<23;k++)
                            {
                                if(G[j][k]==1)
                                {
                                    G[j][k]--;
                                    G[k][j]--;
                                    E[k]--;
                                    E[j]--;
                                    edge--;
                                }
                            }
                        }
                    }
                }
            }
            if(flag) break; 
        }
        if(edge==0) break;
        int max=0;
        int edgemax=E[0];
        for(int i=1;i<23;i++)
        {
            if(E[i]>edgemax)
            {
                edgemax = E[i];
                max = i;
            }
        }
        coververtex[num]=max+1;
        num++;
        for(int i=0;i<23;i++)
        {
            if(G[max][i]==1)
            {
                G[max][i]--;
                G[i][max]--;
                E[max]--;
                E[i]--;
                edge--;
            }
        }
    }
    printf("最小顶点覆盖序列为:");
    for(int i=0;i<num;i++)
    {
        printf("%d ",coververtex[i]);
    }
    printf("最小顶点覆盖数为:%d",num);

    return 0;
}
