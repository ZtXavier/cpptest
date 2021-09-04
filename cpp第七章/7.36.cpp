#include<cctype>
#include<iostream>

struct X
{
    X(int i,int j) : base(i),rem(i % j){std::cout << base << "\n" << rem << std::endl;}  //::是类作用符，:作为初始化成员符
    int rem,base;          //初始化的顺序与定义的顺序相关
};

int main(void)
{
    X x(1,2);
    getchar();
    return 0;
}