#include <stdio.h>
#include <math.h>
#include <stdlib.h>


struct Divisor{
    int divisor;
    int times;
};

struct Nodes
{   struct Divisor divisors;
    struct Nodes *next;
};


int main(){
    int n,m,i = 2,flag = 0,flag2 = 1,count=1;
    struct Nodes *node;
    struct Nodes *p;
    struct Nodes *temp;
    node = (struct Nodes *)malloc(sizeof(struct Nodes));
    p = node;
    printf("请输入待分解的正整数：");
    scanf("%d",&n);
    m = n;
    while(flag == 0){
        for(;i<=sqrt(m);i++){
            if(m%i == 0){
                m = m/i;
                if (flag2){
                    (*p).divisors.divisor = i;
                    (*p).divisors.times = 1;
                    flag2 = 0;
                    break;
                }


                if((*p).divisors.divisor != i){
                    
                    temp = (struct Nodes *)malloc(sizeof(struct Nodes));
                    p->next = temp;
                    p = (*p).next;
                    count += 1;
                    (*p).divisors.divisor = i;
                    (*p).divisors.times = 1;
                    
                }else{  
                    (*p).divisors.times += 1;
                }
                
                break;
            }    
        }
        if(i > sqrt(m)){
                if (flag2){
                    (*p).divisors.divisor = m;
                    (*p).divisors.times = 1;
                    flag2 = 0;
                    break;
                }
                if((*p).divisors.divisor != m ){
                    temp = (struct Nodes *)malloc(sizeof(struct Nodes));
                    p->next = temp;
                    p = (*p).next;
                    count += 1;
                    (*p).divisors.divisor = m;
                    (*p).divisors.times = 1;
                }else{
                    (*p).divisors.times += 1;
                }
                
                flag = 1;
            }

    }
    i = 0;
    while(i<count){
        printf("质因数%d的个数为%d\n",(*node).divisors.divisor,(*node).divisors.times);
        node = (*node).next;
        i += 1;
    }
    return 0;       

}



