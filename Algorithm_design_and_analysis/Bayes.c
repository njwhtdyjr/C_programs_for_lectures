#include <stdio.h>

typedef struct {
    int color;//青绿为0，乌黑为1，浅白为2
    int root;//蜷缩为0，稍蜷为1，硬挺为2
    int knock;//浊响为0，沉闷为1，清脆为2
    int texture;//清晰为0，稍糊为1，模糊为2
    int umbilicus;//凹陷为0，稍凹为1，平坦为2
    int touch;//硬滑为0，软粘为1
    int good;//是为1，否为0
} Watermelon;

int main(void)
{
    Watermelon *watermelon[17];
    Watermelon w1={0,0,0,0,0,0,1};watermelon[0] = &w1;
    Watermelon w2={1,0,1,0,0,0,1};watermelon[1] = &w2; 
    Watermelon w3={1,0,0,0,0,0,1};watermelon[2] = &w3;
    Watermelon w4={0,0,1,0,0,0,1};watermelon[3] = &w4;
    Watermelon w5={2,0,0,0,0,0,1};watermelon[4] = &w5;
    Watermelon w6={0,1,0,0,1,1,1};watermelon[5] = &w6;
    Watermelon w7={1,1,0,1,1,1,1};watermelon[6] = &w7;
    Watermelon w8={1,1,0,0,1,0,1};watermelon[7] = &w8;
    Watermelon w9={1,1,1,1,1,0,0};watermelon[8] = &w9;
    Watermelon w10={0,2,2,0,2,1,0};watermelon[9] = &w10;
    Watermelon w11={2,2,2,2,2,0,0};watermelon[10] = &w11;
    Watermelon w12={2,0,0,2,2,1,0};watermelon[11] = &w12;
    Watermelon w13={0,1,0,1,0,0,0};watermelon[12] = &w13;
    Watermelon w14={2,1,1,1,0,0,0};watermelon[13] = &w14;
    Watermelon w15={1,1,0,0,1,1,0};watermelon[14] = &w15;
    Watermelon w16={2,0,0,2,2,0,0};watermelon[15] = &w16;
    Watermelon w17={0,0,1,1,1,0,0};watermelon[16] = &w17;
    
    Watermelon test;
    printf("请输入待测样例：\n");
    double color[2]={0,0},root[2]={0,0},knock[2]={0,0},texture[2]={0,0},umbilicus[2]={0,0},touch[2]={0,0},good[2]={0,0};
    scanf("%d %d %d %d %d %d",&test.color,&test.root,&test.knock,&test.texture,&test.umbilicus,&test.touch);
    for(int i=0;i<17;i++)
    {
        if(watermelon[i]->good==1)
        {
            good[0]++;
            if(watermelon[i]->color==test.color) color[0]++;
            if(watermelon[i]->root==test.root) root[0]++;
            if(watermelon[i]->knock==test.knock) knock[0]++;
            if(watermelon[i]->texture==test.texture) texture[0]++;
            if(watermelon[i]->umbilicus==test.umbilicus) umbilicus[0]++;
            if(watermelon[i]->touch==test.touch) touch[0]++;
        }
        else
        {
            good[1]++;
            if(watermelon[i]->color==test.color) color[1]++;
            if(watermelon[i]->root==test.root) root[1]++;
            if(watermelon[i]->knock==test.knock) knock[1]++;
            if(watermelon[i]->texture==test.texture) texture[1]++;
            if(watermelon[i]->umbilicus==test.umbilicus) umbilicus[1]++;
            if(watermelon[i]->touch==test.touch) touch[1]++;
        }
    }
    double pgood=1,pbad=1;
    pgood = (good[0]/(good[0]+good[1]))*(color[0]/good[0])*(root[0]/good[0]*(knock[0]/good[0]))*(texture[0]/good[0])*(umbilicus[0]/good[0])*(touch[0]/good[0]);
    pbad = (good[1]/(good[0]+good[1]))*(color[1]/good[1])*(root[1]/good[1]*(knock[1]/good[1]))*(texture[1]/good[1])*(umbilicus[1]/good[1])*(touch[1]/good[1]);
    if(pgood > pbad) printf("是好瓜");
    else printf("不是好瓜");

    return 0;
}