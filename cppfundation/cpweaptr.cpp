#include<iostream>
#include<memory>

struct A;
struct B;

struct A 
{
    std::shared_ptr<B> pointer;
    ~A(){std::cout << " A destroy" << std::endl;}
};

struct B
{
    std::shared_ptr<A> pointer;
    ~B(){ std::cout << "B destroy" << std::endl; }
};

int main()
{
    // 这里就需要注意，当我们给每个类内部引用指针时在类被析构时一定要将智能指针析构掉，否则无法找到类的实例化会导致内存泄漏
    // 这里的解决方法就是使用weak_ptr
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a.pointer = b;
    b.pointer = a;
    return 0;
}