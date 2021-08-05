#include <stdio.h>
#include<string.h>
#include<stdlib.h>
union un{
    int a;
    char ch;
};

int main(int argc, char **argv){
    int num = 0x40414041;
     char *b =(char*)&num;
    printf("%c %c\n",*b,*(b+1));
    return 0;
}