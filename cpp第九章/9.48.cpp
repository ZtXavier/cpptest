#include<iostream>
#include<string>

int main()
{
    std::string number("0123456789"),name("r2d2");
    auto pos = number.find(name) ;
    std::cout << pos << std::endl;
    return 0;
}