#include<iostream>
#include<cctype>
#include<string>

class NoDefault
{
    public:
    NoDefault(int a) {nonum = a;}
    int nonum;
};

class C
{
    public:
    C() : n(0) {}   //在C类中初始化NoDefault类
    void print() {std::cout << n.nonum << std::endl;}
    private:
    NoDefault n;

};

int main(void)
{
    C c;
    c.print();
    return 0;
};