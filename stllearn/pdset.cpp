#include<iostream>
#include<set>

void multisetprint(std::multiset<int> &l)
{
    for(std::multiset<int>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::set<int>s1;
    s1.insert(10);
    std::pair<std::set<int>::iterator,bool> p1;  //pair对组可以来接收set的插入情况
    p1 = s1.insert(10);
    if(p1.second)
    {
        std::cout << "插入成功" << std::endl;
    }
    else
    {
        std::cout << "插入失败"  << std::endl;
    }

    std::multiset<int> m1;       //multiset判断插入成功
    m1.insert(20);
    m1.insert(20);
    multisetprint(m1);
}


int main()
{
    test01();
    return 0;
}