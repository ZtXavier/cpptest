#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//查看一个函数的地址，用到函数指针 数据类型 (*自定义符号)(形参)

static unsigned int PFN_ARR[100] = {0};
void func1(void);
void func2(int a);

void func1(void)
{
    void (*pfn)(void) = func1;  //函数名就是函数所占的首地址
    unsigned int func_addr = (unsigned int)pfn;
    PFN_ARR[0] = func_addr;
    printf("func1:%X\n",func_addr);
}

void func2(int a)
{
    void(*pfn)(int) = func2;
    unsigned int func_addr = (unsigned int)pfn;
    PFN_ARR[1] = func_addr;
    printf("func2:%X\n",func_addr);
}

int main(void)
{
    void(*pfn)();
    func1();
    func2(5);
    // pfn = (void(*)())(PFN_ARR[0]);
    // pfn();
    getchar();
    return 0;
}