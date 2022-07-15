#include<iostream>
#include<functional>


int foo(int a,int b,int c)
{
    std::cout << a <<  " " << b << " " << c  << std::endl;
}


int main()
{
    auto bindfoo = std::bind(foo,std::placeholders::_1,1,2);
    bindfoo(15);
    return 0;
}