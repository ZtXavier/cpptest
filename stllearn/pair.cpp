#include<iostream>

//对组不需要包含头文件

void test01()
{
    std::pair<char,int> p1('a',48); //构造创建
    std::cout << p1.first << " " << p1.second << std::endl;
    std::pair<char,int> p2 = std::make_pair('b',49);   //在命名空间std中来使用make_pair创建
    std::cout << p2.first << " " << p2.second << std::endl;
}

int main()
{
    test01();
    return 0;
}