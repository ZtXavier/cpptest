#include<iostream>
#include<list>

//注意：list不支持随机访问，不可以使用at()函数和对其迭代器进行it+1,it+2.etc操作
void test01()
{
    std::list<int> l1;
    for(int i = 0;i < 9;i++)
    {
        l1.push_back(i);
    }
    int a = 0;
    a = l1.front();
    std::cout << a << std::endl;
    std::cout << l1.back() << std::endl;
}


int main()
{
    test01();
    return 0;
}