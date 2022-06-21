#include<iostream>


// 拓展constexpr 的使用范围，用于if
template<bool ok>
constexpr  void foo()
{
    // 在编译期判断
    if constexpr (ok == true)
    {
        // 当ok为true时只有下面的代码
        std::cout << "ok" << std::endl;
    }
    else
    {
        std::cout << "not ok" << std::endl;
    }
}

int main()
{
    foo<true>();
    foo<false>();
    return 0;
}