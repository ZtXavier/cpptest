#include<iostream>
#include<string>
#include<cctype>
#include<deque>


void test01(void)
{
    std::string ss;
    std::deque<std::string> s1;
    while(std::cin >> ss)
    {
        s1.push_back(ss);
    }
    std::deque<std::string>::iterator it = s1.begin();
    while(it != s1.end())
    {
        std::cout << *it++ <<" ";
    }
    std::cout << std::endl;
}


int main(void)
{
    test01();
    return 0;
}