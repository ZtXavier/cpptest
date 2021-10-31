#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
void test01(void)
{
    std::vector<int> v1;
    v1.reserve(10);
    std::vector<int>::iterator it = v1.begin();
    auto n = std::back_inserter(v1);         //back_inserter返回迭代器类型，是一种插入迭代器，会向容器中插入元素
    // std::fill_n(n,10,9);
    std::list<int> lst;
    int i;
    while(std::cin >> i)
    {
        lst.push_back(i);
    }
    std::copy(lst.begin(),lst.end(),n);
    for(std::vector<int>::iterator it = v1.begin();it != v1.end();it++)
    std::cout << *it << std::endl;
}
//10.8  标准库算法不会改变他们所操作的容器的大小，迭代器会改变容器的大小

int main()
{
    test01();
    return 0;
}