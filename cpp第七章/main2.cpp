#include<iostream>
#include<string>
#include"header.h"

bool flag = false;
extern int num;

int main(void)
{
    int numa = 10;
    std::cout << numa << "! = " << factorial(numa) << std::endl;
    std::cout << numb << "! = " << factorial(numb) << std::endl;
    std::cout << num << "! = " << factorial(num) << std::endl;
    if(flag)
    {
        std::cout << "llll" << std::endl;
    }
    return 0;
}