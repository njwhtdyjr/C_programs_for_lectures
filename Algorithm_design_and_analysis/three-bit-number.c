#include <stdio.h>

int main()
{
    int a,b,c;
    for(a=0;a<=7;a++)
        for(b=a+1;b<=8;b++)
            for(c=b+1;c<=9;c++)
                if(a+b+c == a*b*c)
                {
                    printf("%d",a*10+b*100+c);
                }
    return 0;
}