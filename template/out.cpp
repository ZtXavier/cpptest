#include<iostream>

template<class T1,class T2>
class Base
{
    public:
    Base(T1 name,T2 age);
    void showdata();
    private:
    T1 name;
    T2 age;
};

//若在外部定义类模板函数实现时，应加上类模板参数列表
template<class T1,class T2>
Base<T1,T2>::Base(T1 name,T2 age)
{
    this->name = name;
    this->age = age;
}

template<class T1,class T2>
void Base<T1,T2>::showdata()
{
    std::cout << name << " " << age << std::endl;
}

void test1()
{
    Base<std::string,int> p("ss",100);
    p.showdata();
}
int main(void)
{
    test1();
    return 0;
}