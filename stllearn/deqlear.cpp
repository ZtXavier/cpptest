#include<iostream>
#include<vector>
#include<deque>


void printdeq(std::deque<int> &s)
{
    for(std::deque<int>::iterator it = s.begin();it != s.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::deque<int> d1;
    for(int i = 0;i < 10;i++)
    {
        d1.push_back(i);
    }
    printdeq(d1);
    std::deque<int> d2(10,88);
    std::deque<int> d3(d1.begin(),d1.end());
    std::deque<int> d4(d3);
    std::deque<int> d5;
    d5.assign(d2.begin(),d2.end());
    std::deque<int> d6;
    d6.assign(10,100);
    printdeq(d2);
    printdeq(d3);
    printdeq(d4);
    printdeq(d5);
    printdeq(d6);
}

int main()
{
    test01();
    return 0;
}