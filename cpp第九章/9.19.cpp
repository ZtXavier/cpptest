#include<iostream>
#include<list>
#include<cctype>
#include<string>


void test01(void)
{
    std::string s1;
    std::list<std::string> l1;
    std::list<std::string>::iterator it = l1.begin();
    while(std::cin >> s1)
    {
        it = l1.insert(it,s1);
    }
    while(it != l1.end())
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