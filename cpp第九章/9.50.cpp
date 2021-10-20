#include<iostream>
#include<string>
#include<vector>

void test01()
{
    std::vector<std::string> v1 = {"14","124","2345"};
    std::vector<std::string>::iterator it = v1.begin();
    int num = 0;
    while(it != v1.end())
    {
        num += std::stoi((*it));
        std::cout << num << std::endl;
        (it++);
    }
}

int main()
{
    test01();
    return 0;
}