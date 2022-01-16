#include<iostream>
#include<functional>


//内建仿函数 实现加减乘除等运算


void test01()
{
    std::negate<int> n;
    std::cout << n(100) << std::endl;
}


void test02()
{
    std::plus<int> add;
    std::cout << add(10,20) << std::endl;
}

int main()
{
    test02();
    return 0;
}