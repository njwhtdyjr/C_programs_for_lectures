#include <stdio.h>
#include <windows.h>
int main()
{   int i=1;
    int array[3]={1,2,3};
    char string[]="three-body与三";
    int *pi = &i;
    printf("%d",*pi);
    for(i=0;i<3;i++)
    {   printf("%s",string);
        printf("%d",array[i]);
        printf("%d",strlen(string));
    }

    return 0;
    
}
