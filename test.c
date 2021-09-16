#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// union un{
//     int a;
//     char ch;
// };
int compare_(int **a,int **p){
    int *temp;
    temp = &(**a);        //c语言中两种交换指针所指的地址方式
    *a = &(**p);
    *p = temp;
    // temp = *a;
    // *a = *p;
    // *p = temp;
    return 0;
}
int main(int argc, char **argv){
    // int num = 0x40414041;
    // char *b =(char*)&num;
    // printf("%c %c\n",*b,*(b+1));

    // int i = 5;
    // int a = 10;
    // int *p ;
    // p = &a;
    // int *j ;
    // j = &i;
    // printf("%d %d\n",*j,*p);
    // compare_(&j,&p);
    // printf("%d %d\n",*j,*p);
    int *p = NULL;                 //0~255编号是系统占用的不可访问
    *p = 2;
    printf("%d",*p);
    return 0;
}