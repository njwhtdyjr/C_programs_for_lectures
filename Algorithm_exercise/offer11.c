#include <stdio.h>
int main(void)
{
    return 0;
}
int minArray(int* numbers, int numbersSize){
    if(numbersSize==1)return numbers[0];
    int i;
    for(i=1;i<numbersSize;)
    {
        if((numbers[i]-numbers[i-1])>=0)i++;
        else break;
    }
    if(i==numbersSize)return numbers[0];
    else return numbers[i];
}