#include<iostream>

class Base {
    public:
        virtual void B_func1() { std::cout << "Base:: B_func1()" << std::endl; }
        virtual void B_func2() { std::cout << "Base::B_func2()" << std::endl; }
        virtual void B_func3() { std::cout << "Base::B_func3()" << std::endl; }
};

class Derive : public Base {
    public:
        virtual void D_func1() { std::cout << "Derive::D_func1()" << std::endl; }
        virtual void D_func2() { std::cout << "Derive::D_func2()" << std::endl; }
        virtual void D_func3() { std::cout << "Derive::D_func3()" << std::endl; }
};


int main() {
    Base *p = new Derive();
    p->B_func1();
    // p->D_func1();
    Derive *d = new Derive();
    d->D_func1();
    d->B_func1();
    return 0;
}