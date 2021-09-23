#include<iostream>
//1.如果函数模板和普通函数都可以实现，优先调用普通函数
//2.可以通过空模板参数列表来强制调用函数模板
//3.函数模板也可发生重载
//4.如果函数模板可以产生更好的匹配，优先调用函数模板

void mytest(int &a)
{
    std::cout << "普通函数" << std::endl;
}

template<class T>
void mytest(T &a)
{
    std::cout << "模板函数" << std::endl;
}
//以上函数调用会优先调用普通函数

template<class T>
void mytest(T a,T b)
{
    std::cout << "模板重载函数" << std::endl;
}


int main(void)
{
    int a = 1;
    char ch = 'c';
    mytest(a);                    //当普通函数与模板函数都在优先考虑普通函数
    mytest<int>(a);               //可以强制使用模板函数
    mytest<int>(a,a);             //模板函数可以函数类型重载
    mytest(ch);                   //当需要数据类型转换时优先考虑模板函数
    mytest<int>(a,ch);            //当使用模板函数使用隐式类型转换会报错，但是使用显式类型会成功，但是不能使用引用类型
    return 0;
}