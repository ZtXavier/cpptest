#include<iostream>
#include<vector>

void test01()
{
    std::vector<std::string> vec = {"dawaw","dyjj","fawf","rtyt"};
    vec.resize(100);
    for(auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    vec.resize(2);
    for(auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    test01();
    return 0;
}