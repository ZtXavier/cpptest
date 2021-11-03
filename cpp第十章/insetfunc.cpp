#include<iostream>
#include<algorithm>
#include<string>

//实现取反
void test01()
{
    std::negate<int> n;
    std::cout << n(20) << std::endl;
}

void test02()
{
    std::plus<int> p;
    std::cout << p(1,2) << std::endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}