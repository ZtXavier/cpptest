#include<iostream>

int main(void)
{
    // int &a = 10;     // 错误写法，不能直接引用一个常量
    const int &b = 10;  //由于const的修饰，其实质是int temp = 10,const int &b = temp;
    std::cout << b << std::endl;
    return 0;
}