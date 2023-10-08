#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isNumber(char* s);

int main(void)
{
    return 0;
}

bool isNumber(char* s)
{
    
    int i=0;
    bool dot=false,dotnumber=false,numberdot=false;
    while(s[i]==' ')
    {
        i++;
    }
    if(s[i]=='\0') return false;
    if(isalpha(s[i])) return false;
    if(s[i]=='+' || s[i]=='-')
    {   
        i++;
    }
    while(s[i]!='e' && s[i]!='E' && s[i]!=' ' && s[i]!='\0')
    {
        if(isalpha(s[i])) return false;
        if(s[i]=='+' || s[i]=='-') return false;
        if(isdigit(s[i]))
        {   
            if(!dot)numberdot=true;
            if(dot) dotnumber=true;
        }
        if(s[i]=='.')
        {   
            if(dot) return false;
            dot = true;
        }
        i++;
    }
    if(numberdot==false && dotnumber==false) return false;
    
    if(s[i]=='\0') return true;
    if(s[i]==' ')
    {
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]!='\0')return false;
        else return true;
    }
    i++;
    if(s[i]=='+' || s[i]=='-')
    {   
        i++;
    }
    numberdot = false;
    while(s[i]!=' ' && s[i]!='\0')
    {
        if(isalpha(s[i])) return false;
        if(s[i]=='+' || s[i]=='-') return false;
        if(isdigit(s[i]))
        {   
            numberdot=true;
        }
        if(s[i]=='.')return false;
        i++;
    }
    if(numberdot==false) return false;
    if(s[i]=='\0') return true;
    else 
    {
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]!='\0')return false;
        else return true;
    }   
}
