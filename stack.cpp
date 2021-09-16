#include<iostream>
#include<string>

int *func()
{
    int a = 10;
    return &a;  //在函数结束后会被释放掉
}

int main(void)
{
    int *a;
    a = func();
    std::cout << "1- " << a << std::endl;
    std::cout << "1- " << *a << std::endl;
    std::cout << "2- " << a << std::endl;
    std::cout << "2- " << *a << std::endl;
    return 0;
}
