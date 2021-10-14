#include<iostream>
#include<deque>

//deque容器没有容量的定义

void printdeq(std::deque<int> &s)
{
    for(std::deque<int>::iterator it = s.begin();it != s.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    if(s.empty())
    {
        std::cout << "is empty" << std::endl;
    }
    else
    {
        std::cout << "not empty" << std::endl;
    }
}




void test01()
{
    std::deque<int> d1;
    for(int i = 0;i < 10;i++)
    {
        d1.push_back(i);
    }
    std::cout << "大小为 " << d1.size() << std::endl;
    printdeq(d1);
    d1.resize(15,7);
    printdeq(d1);
    d1.resize(5);
    printdeq(d1);
}


int main()
{
    test01();
    return 0;
}