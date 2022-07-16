#include<iostream>
#include<exception>

//使用 noexcept 修饰过的函数如果抛出异常，编译器会使用 std::terminate() 来立即终止程序运行。
// noexcept 修饰完一个函数之后能够起到封锁异常扩散的功效，如果内部产生异常，外部也不会触发。
void may_throw()
{
    throw true;
}

auto non_block_throw = []{
    may_throw();
};

void no_throw() noexcept
{
    return ;
}

auto block_throw = []() noexcept
{
    no_throw();
};

int main()
{
    //noexcept 还能够做操作符，用于操作一个表达式，当表达式无异常时，返回 true，否则返回 false
    std::cout << std::boolalpha
    << "may_ ?" << noexcept(may_throw()) << std::endl
    << "no_ ?" << noexcept(no_throw()) << std::endl
    << "lmay_ ?" << noexcept(non_block_throw()) << std::endl
    << "lno_ ?" << noexcept(block_throw()) << std::endl;
    return 0;
}