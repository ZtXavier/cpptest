#include<iostream>
#include<string.h>



typedef struct String
{
    int strlen;
    char str[16];
}Str;


void getnext(Str *t,int next[])
{
    int k = -1,j = 0;
    next[0] = -1;
    while(j < t->strlen)
    {
        if(k == -1 || t->str[k] == t->str[j])
        {
            j++;k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    
}

void mystrcpy(char *s,char *p)
{
    int i = 1;
    int len = strlen(p)+1;
    for(;i <= len;i++)
    {
        s[i] = p[i-1];
    }
    s[i] = '\0';
}

int main()
{
    Str *s = new Str;
    char p[16] = "aaabaaa";
    mystrcpy(s->str,p);
    s->strlen = strlen(p);
    int next[s->strlen];
    getnext(s,next);
    for(int i = 1;i <= s->strlen;i++)
    {       
    printf("%c %d\n",s->str[i],next[i]);
    }
    return 0;
}