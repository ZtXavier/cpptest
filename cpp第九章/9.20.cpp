#include<iostream>
#include<list>
#include<deque>

void test01(void)
{
    std::deque<int> d1,d2;
    std::list<int> l1 = {1,2,3,4,5,6,7};
    std::list<int>::iterator it = l1.begin();
    while(it != l1.end())
    {
        if(*it%2 == 0)
        {
            d2.push_back(*it++);
        }
        else
        {
            d1.push_back(*it++);
        }
    }
    std::deque<int>::iterator fr1 = d1.begin() , fr2 = d2.begin();
    while(fr1 != d1.end())
    {
        std::cout << *fr1++ << " ";
    }
    std::cout << std::endl;
    while(fr2 != d2.end())
    {
        std::cout << *fr2++ << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    test01();
    return 0;
}