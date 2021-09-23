#include<iostream>
template<class T>   //typename函数类型模板，class既可以用类模板，也可以用函数模板
void My_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T>   //该T的类型必须一致
void test()
{
    std::cout << "test" << std::endl;
}
void test1()
{
    // test();         //当该定义时会导致编译器无法知道模板数据类型所以应改为test<int>()进行声明
    test<void>();
}

int main(void)
{
    int a = 11;
    int b = 20;
    // My_swap(a,b);
    // My_swap<int>(a,b);
    test1();
    std::cout << a << " " << b << std::endl;
    return 0;
}