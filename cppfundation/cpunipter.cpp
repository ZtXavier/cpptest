#include<iostream>
#include<string>
#include<memory>

// 这里的指针不可引用

template<typename T,typename ...Args>
std::unique_ptr<T> make_unique(Args && ...args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//不可独占，换句话说就是不可复制。但是，我们可以利用 std::move 将其转移给其他的 unique_ptr

struct Foo
{
    Foo(){ std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; } 
};

void f(const Foo &)
{
    std::cout << "f(const Foo&)" << std::endl;
}

int main()
{
    std::unique_ptr<Foo> p1(std::make_unique<Foo>());
    if(p1)   p1->foo();
    {
    std::unique_ptr<Foo> p2(std::move(p1));
    f(*p2);
    if(p2)   p2->foo();        
    // if(p1) p1->foo(); // p1失效
    p1 = std::move(p2);
    // if(p2) p2->foo(); // p2 失效
    std::cout << "p2 destroyed" << std::endl;
    }
    if(p1) p1->foo();
    return 0;
}