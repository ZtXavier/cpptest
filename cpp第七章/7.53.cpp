#include<iostream>
#include"7.53.h"

int main(void)
{
    constexpr Debug io_sub(false,true,false);    //调试IO
    if(io_sub.any())                             //等价于if(true)
    std::cerr << "print appropriate error messages" << std::endl;
    constexpr Debug prod(false);                 //无调试
    if(prod.any())                               //等价于if(false)
    std::cerr << "print an error message" << std::endl;
    return 0;
}