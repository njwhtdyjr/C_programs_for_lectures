#include <stdio.h>
#include <stdlib.h>
char* replaceSpace(char* s);
int main(void)
{
    char s[100]="We are happy.";
    char *s1;
    s1 = replaceSpace(s);
    printf("%s",s1);
    free(s1);
    return 0;
}
char * replaceSpace(char*s)
{   
    int i=0,j=0,cnt=0,space=0;
    while(s[cnt]!='\0')
    {   
        if(s[cnt]==' ')
        space++;
        cnt++;
    }
    char *s1;
    s1 = (char*)malloc((cnt+1+space*2)*sizeof(char));
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            s1[j]='%';
            s1[j+1]='2';
            s1[j+2]='0';
            j+=3;
            i+=1;
        }
        else
        {
            s1[j]=s[i];
            j++;
            i++;
        }
    }
    s1[j]='\0';
    return s1;
}