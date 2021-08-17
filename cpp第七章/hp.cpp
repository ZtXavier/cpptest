#include<iostream>
#include<cctype>
#include<string>

int swap(int *a,int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    return 0;
}

int main(void)
{
    int a = 10,b = 7;
    std::cout << a << " " << b << std::endl;
    int (*poit)(int*,int*); //函数指针的声明
    poit = swap;
    (*poit)(&a,&b);
    std::cout << a << " " << b << std::endl;
    return 0;
}