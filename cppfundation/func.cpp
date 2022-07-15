#include<iostream>
#include<functional>



int foo(int p)
{
    return  p;
}

int main()
{
    // 对函数进行一个包装
    std::function<int(int)> func = foo;

    int im = 10;
    // 当值捕获时只能作为右值，引用捕获时可以成为左值或者右值
    std::function<int(int)> func2 = [=](int value)->int 
    {
        return 1 + value + im;
    };
    std::cout << im << std::endl;
    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
    return 0;
}