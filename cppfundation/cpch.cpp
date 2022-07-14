#include<iostream>
#include<string>

class Base
{
    public:
        int value1;
        int value2;
        Base()
        {
            value1 = 1;
        }
        Base(int v): Base()    // c++17 委托构造
        {
            value2 = v;
        }

};


int main()
{
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;
    return 0; 
}