#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isMatch(char* s, char* p);

int main(void)
{   
    char * s = "ab";
    char * p = ".*";
    printf("%d",isMatch(s,p));
    return 0;
}

bool isMatch(char *s,char*p)
{   
    if(s[0]=='\0' && p[0]!='\0')
    {
        int i=0;
        while(p[i+1]=='*')
        {
            i+=2;
            if(p[i]=='\0')
            return true;
        }
        return false;
    }
    if(s[0]!='\0' && p[0]=='\0')return false;
    if(s[0]=='\0' && p[0]=='\0')return true;
    int i=0,j=0;
    while(s[i]!='\0' && p[j]!='\0')
    {
        if((s[i]==p[j] || p[j] =='.') && p[j+1]!='*')
        {
            i++;
            j++;
            
        }
        else
        {
            if(s[i]!=p[j] && p[j]!='.')
            {
                if(p[j+1]!='*')
                return false;
                else {
                    j+=2;
                }
            }
            else
            {
                if(s[i]==p[j])
                {   
                    char temp = s[i];
                    int cnt=0;
                    while(s[i+cnt]==temp) cnt++;
                    bool flag=false;
                    for(int k=0;k<=cnt;k++)
                    {
                        if(isMatch(s+i+k,p+j+2))
                        flag = true;
                    }
                    return flag;
                
                }
                else
                {
                    int cnt=0;
                    while(s[i+cnt]!='\0')cnt++;
                    bool flag =false;
                    for(int k =0;k<=cnt;k++)
                    {
                        if(isMatch(s+i+k,p+j+2))
                        flag =true;  
                    }
                    return flag;
                }
            }

        }
        
    }

    if(s[i]=='\0' && p[j]!='\0')
    {  
        while(p[j+1]=='*')
        {
            j+=2;
            if(p[j]=='\0')return true;
        }
        return false;
    }
    if(s[i]!='\0' && p[j]=='\0')return false;
    else return true;
}