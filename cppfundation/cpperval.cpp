#include<iostream>
#include<utility>


void reference(int& v)
{
    std::cout << "左值引用" << std::endl;
}

void reference(int && v)
{
    std::cout << "右值引用" << std::endl;
}

template<typename T>
void pass(T && v)
{
    std::cout << " commen pass" << std::endl;
    reference(v);
    std::cout << " std::move pass" << std::endl;
    reference(std::move(v));
    std::cout << " std::forward pass" << std::endl;
    reference(std::forward<T>(v));
    std::cout << " static_cast<T&&> pass" << std::endl;
    reference(static_cast<T&&>(v));
}

int main()
{
    std::cout << "pass right" <<std::endl;
    pass(1);
    std::cout << std::endl;
    std::cout << "pass left " << std::endl;
    int v1 = 2;
    pass(v1);
    return 0;
}