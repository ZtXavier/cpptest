#include<iostream>
#include<string>

using foo = void(int);

void functional(foo f)
{
    f(3);            // 这里相当于传进来一个函数表达式作为函数的形参
}

int main()
{
    auto f = [](int value)
    {
        std::cout << value << std::endl;
    };
    functional(f);
    f(1);
    return 0;
}