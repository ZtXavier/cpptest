#include<iostream>


int main()
{
    int *p = 0;      //一个指针指向不确定的地址结果也会不确定
    //char a[] = "asfg";
    //char c = a[10];
    std::cout << *p << std::endl;
    return 0;
}