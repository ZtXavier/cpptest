#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// #include<assert.h>
#include"my_assert.h"













// #define Swap1(a,b,c)    \
// do{                     \
//     c = a;              \
//     a = b;              \
//     b = c;              \
// }while(0)              \




// union un{
//     int a;
//     char ch;
// };
// int compare_(int **a,int **p){
//     int *temp;
//     temp = &(**a);        //c语言中两种交换指针所指的地址方式
//     *a = &(**p);
//     *p = temp;
//     // temp = *a;
//     // *a = *p;
//     // *p = temp;
//     return 0;
// }



    // int *func1(void)
    // {
    //     static int n = 0;
    //     n = 1;
    //     return &n;
    // }
    // int *func2(void)
    // {
    //     int *p = (int *)malloc(sizeof(int));
    //     *p = 3;
    //     return p;
    // }

    // int *func3(void)
    // {
    //     int n = 4;
    //     return &n;
    // }

int main(int argc, char **argv)
{


    FILE *fp;
    fp = fopen("正则.txt","w");
    assert( fp );
    fclose(fp);

    FILE *fp2;
    fp2 = fopen("adaw.txt","r"); //只读打开不存在的文件会报错
    assert(fp2);
    fclose(fp2);

    // int a = 5;
    // int b = 3;
    // int c = 2;
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
    // int *p = NULL;                 //0~255编号是系统占用的不可访问
    // *p = 2;
    // printf("%d",*p);
    // *func1() = 4;
    // *func2() = 5;
    // *func3() = 6;
    // Swap1(a,b,c);
    // printf("%d %d",a,b);
    return 0;
}