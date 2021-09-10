#include<iostream>
#include<string>

constexpr int new_sz()
{
    return 42+10;
}
int main(void)
{
    constexpr auto foo = new_sz(); //foo是一个常量表达式
    std::cout << foo << std::endl;
    return 0;
}