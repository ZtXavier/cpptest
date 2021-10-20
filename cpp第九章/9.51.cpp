#include<iostream>
#include<string>
#include<vector>

void test01()
{
    std::vector<std::string> v1 = {"14.2","124.8","2345.12345"};       //如果里面有字符会报错
    std::vector<std::string>::iterator it = v1.begin();
    double num = 0.0;
    std::cout.precision(5);
    std::cout.flags(std::cout.fixed);
    while(it != v1.end())
    {
        num += std::stod((*it));
        std::cout << num << std::endl;
        (it++);
    }
}

int main()
{
    test01();
    return 0;
}