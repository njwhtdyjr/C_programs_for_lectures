#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct item{
    
    int nowvalue;
    struct item * next;
}Item;
typedef struct 
{
    int x;
    int y;
} Direction;





Item * CreateStack(void);
void PushStack(Item **head);
void PopStack(Item **head);
bool exist(char** board, int boardSize,int *boardColSize,char* word);

int main(void)
{

    char *board[3];
    char s1[3] = {'C','A','A'};
    char s2[3] = {'A','A','A'};
    char s3[3] = {'B','C','D'};
    
    board[0] = s1;
    board[1] = s2;
    board[2] = s3;

    
    int boardColSize[3]={3,3,3};
    char * word = "AAB";
    printf("%d",exist(board,3,boardColSize,word));
    return 0;
}

Item * CreateStack(void)
{
    Item * head = NULL;
    return head;
}

void PushStack(Item **head)
{
    Item * temp;
    temp = (Item *)malloc(sizeof(Item));
   
    temp->nowvalue = -1;
    temp->next = *head;
    *head = temp;
}
void PopStack(Item **head)
{
    if (*head == NULL) return -1;
    Item * temp;
   
    temp = (*head)->next;
   
    free(*head);
    *head = temp;
}    



bool exist(char** board, int boardSize,int *boardColSize,char* word)
{
    int i,j,k,m,gone[boardSize][boardColSize[0]];
    Direction direction[4];
    direction[0].x = 0;direction[0].y = -1;
    direction[1].x = 1;direction[1].y = 0;
    direction[2].x = 0;direction[2].y = 1;
    direction[3].x = -1;direction[3].y = 0;
    
    for(i=0;i<boardSize;i++)
    {
        for(j=0;j<boardColSize[0];j++)
        {
            gone[i][j] = 0;
        }
    }

    Item * Word;
    Word = CreateStack();
    for(i=0;i<boardSize;i++)
    {   
        for(j=0;j<boardColSize[i];j++)
        {   
            m = 0;
            k = 0;
            if(board[i][j]==word[k])
            {
                PushStack(&Word);
                k++;
                gone[i][j] = 1;
            }
            else continue;
            while(word[k]!='\0')
            {   
                if(k==0) break;
                if(m==4)
                {
                    PopStack(&Word);
                    k--;
                    gone[i][j] = 0;
                    if(k>0)
                    {
                        i -= direction[Word->nowvalue].y;
                        j -= direction[Word->nowvalue].x;
                    }             
                }
                if(k==0) break;
                for(m=Word->nowvalue+1;m<4;m++)
                {   
                    
                    if(((i+direction[m].y)>=0 && (i+direction[m].y)<boardSize)&&((j+direction[m].x)>=0&&(j+direction[m].x)<boardColSize[0]))
                    {
                        if(gone[i+direction[m].y][j+direction[m].x]!=1)
                        {
                            if(board[i+direction[m].y][j+direction[m].x]==word[k])
                            {
                                Word->nowvalue = m;
                                PushStack(&Word);
                                k++;
                                i += direction[m].y;
                                j += direction[m].x;
                                gone[i][j] = 1;
                                break;
                            }
                        }
                    }
                    if(m==3)
                    {
                        PopStack(&Word);
                        k--;
                        gone[i][j] = 0;
                        if(k!=0)
                        {
                            i -= direction[Word->nowvalue].y;
                            j -= direction[Word->nowvalue].x;                            
                        }
                        m = 0;
                        break;
                    }
                }



            }
            if(word[k]=='\0') return true;
        }
    }
    return false;
}

