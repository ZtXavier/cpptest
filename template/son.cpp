#include<iostream>
#include<typeinfo>

template<class T>
class Base
{
    T m;
};

// class son :public Base 错误，由于c++编译其需要给子类分配内存，但是T的数据类型却不知道

class son : public Base<int>
{

};

void test1()
{
    son c;   //该编译器是可通过的
}


//想灵活的指定父类时，就要将子类变为模板类型
template<class T1,class T2>
class son1 : public Base<T2>
{
    public:
    const std::type_info &t1 = typeid(T1);
    const std::type_info &t2 = typeid(T2);
    // const char * a = t1.name();
    // const char * b = t2.name();
    son1()
    {
        std::cout << t1.name() << std::endl;
        std::cout << t2.name() << std::endl;
    }
    private:
    T1 l;

};


void test2()
{
    son1<int,char> s;
}

int main(void)
{
    test1();
    test2();
    return 0;
}