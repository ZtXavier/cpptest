#include<iostream>
#include<string>

void increase(int &v)
{
    v++;
}

void foo()
{
    int s = 1;
    increase(s);
    std::cout << s << std::endl;
}

class A
{
    public:
        int *pointer;
        A():pointer(new int (1))
        {
            std::cout << "construction" << std::endl;
        }
        A(A& a):pointer(new int(*a.pointer))
        {
            std::cout << "copy" << std::endl;
        }
        A(A&& a):pointer(a.pointer)
        {
            a.pointer = nullptr;
            std::cout << "move" << std::endl;
        }
        ~A()
        {
            std::cout << "destroy" << std::endl;
            delete pointer;
        }
};


// 该函数来防止编译器优化
A return_rvalue(bool test)
{
    A a,b;
    std::cout << b.pointer << std::endl;   
    // 下面返回的是类型会变为 static_cast<A&&> a;static_cast<A&&> b;
    if(test) return a;
    else return b;
}



int main()
{
    // 这里使用右值引用来增加变量的周期
    A obj = return_rvalue(false);
    std::cout << "obj" << std::endl;
    std::cout << obj.pointer  << std::endl;
    std::cout << *obj.pointer << std::endl;
    // int &a = std::move(1);      // 错误的写法
    // const int &a = std::move(1);
    // std::cout << a << std::endl;
    return 0;
}


