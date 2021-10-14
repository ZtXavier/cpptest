#include<iostream>
#include<deque>


void printdeq(std::deque<int> &s)
{
    for(std::deque<int>::iterator it = s.begin();it != s.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// 注意：使用insert函数和erase函数时必须使用指针类型或传递地址，不可使用int类型的索引
void test01()
{
    std::deque<int> d1;
    for(int i = 0;i < 5;i++)
    {
        d1.push_back(i);
    }
    std::deque<int> d2(2,50);
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printdeq(d1);
    std::deque<int>::iterator it = d1.begin();
    d1.erase((it+2));
    printdeq(d1);
}

int main()
{
    test01();
    return 0;
}