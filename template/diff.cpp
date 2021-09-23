#include<iostream>

//类模板与函数模板的区别

template<class NameType,class AgeType>
class person
{
public:
    person(NameType name,AgeType age = int)
    {
        this->name = name;
        this->age = age;
    }
    void showperson()
    {
        std::cout << name << " " << age << std::endl;
    }
private:
    NameType name;
    AgeType age;
};

//1.类模板没有自动类型推导的方式
void test()
{
    // person p("s",1); 错误，无法自动类型推导
    person<std::string,int> p("o1",1);
    p.showperson();
}
//2.类模板可以定义默认参数




int main(void)
{
    test();
    return 0;
}



