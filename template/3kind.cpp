#include<iostream>
#include<cctype>


//类模板对象做函数参数
template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age)
    {
        this->name = name;
        this->age = age;
    }
    void showperson()
    {
        std::cout << name << " " << age << std::endl;
    }
    private:
    T1 name;
    T2 age;
};

//1.指定传入类型
void myprintf(person<std::string,int> &p)
{
    p.showperson();
}

void test()
{
    person<std::string,int>p("ll",22);
    myprintf(p);
}

//2.参数模板化
template<class T1,class T2>
void myprintf1(person<T1,T2> &p)
{
    p.showperson();
}

void test1()
{
    person<std::string,int> p("ss",23);
    myprintf1(p);
}

//3.整个类模板化
template<class T>
void myprintf2(T &p)
{
    p.showperson();
    // std::cout << typeid(T).name() << std::endl;
}

void test2()
{
    person<std::string,int> p("aa",24);
    myprintf2(p);
}


int main(void)
{
    test();
    test1();
    test2();
    return 0;

}