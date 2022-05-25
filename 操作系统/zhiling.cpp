#include<iostream>
#include<stdio.h>
#include<unistd.h>





int main(int argc,char* argv[])
{
    int i,to,sum = 0;
    to = atoi(argv[1]);
    printf("%s\n",argv[1]);
    for(i = 1;i <= to;i++)
    {
        sum = sum + i;
        fprintf(stdout,"%d\n",sum);
    }
    return 0;
}