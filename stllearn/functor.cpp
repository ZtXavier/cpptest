#include<iostream>
#include<string>

/* 函数对象:重载函数调用的操作符类，其对象成为函数对象
函数对象在重载()时，行为类似于函数调用，也成为仿函数 */
//本质：仿函数是一个类，不是函数

/* 特点：1.函数对象在使用时可以像普通函数调用，可以有参数，可以有返回值
2.函数对象超出普通函数的概念，函数对象可以有自己的状态
3.函数对象可以作为参数传递 */


class myadd
{
public:
    int operator()(int a,int b)
    {
        return a + b;
    }
};

void test01()
{
    myadd ad;
    std::cout << ad(2,7) << std::endl;   //在这里直接返回两数的和
}


class myprint
{
public:
    myprint(){count = 0;}
    void operator()(std::string test)
    {
        std::cout << test << std::endl;
        count++;
    }
    int count;                         //来定义一个状态
};

void test02()
{
    myprint my;
    my("lll");
    my("lll");
    my("lll");
    std::cout << "打印了" << my.count << "次" << std::endl;
}


void test03(myprint &m,std::string test)
{
    m(test);                               //该仿函数比普通函数更加灵活，能作为参数传入函数
}

int main()
{
    // test01();
    // test02();
    myprint myp;
    test03(myp,"adw");
    return 0;
}