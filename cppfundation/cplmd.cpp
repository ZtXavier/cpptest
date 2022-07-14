#include<iostream>
#include<string>
#include<functional>
using foo = void(*)(int);

void func(foo f)
{
    // f(3);
    std::cout << f << std::endl;
    
}

int main()
{
    auto f = [](int value)
    {
        std::cout << value << std::endl;
    };
    
    func(f);

    // f(2);
    // f(1);
    
    return 0;
}