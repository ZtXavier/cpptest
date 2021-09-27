#include<iostream>
#include<cctype>
#include<vector>
#include<string>


void test01(void)
{
    std::vector<std::string> v1(1,"daw");
    std::cout << v1.at(0) << std::endl;
    std::cout << v1[0] << std::endl;
    std::cout << *v1.begin() << std::endl;
    std::cout << v1.front() << std::endl;
}


int main(void)
{
    test01();
    return 0;
}