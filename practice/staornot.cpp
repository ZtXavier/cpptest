#include<iostream>
#include<vector>
#include<string>

class A {
    public:
        A(int a = 0) {
            std::cout << "enter A: " << a << std::endl;
        }
        ~A() {
            std::cout << "~A()" << std::endl;
        }
};

// 定义一个静态类对象
static A a;

void f() {
    static A c(2);
}

int main() {
    std::cout << "main" << std::endl;
    static A b(1);
    f();
    std::cout << "main-end" << std::endl;
    return 0;
}
