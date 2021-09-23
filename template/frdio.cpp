#include<iostream>
#include<string>

template<class T1,class T2>  //需要将person类模板参数进行声明
class person;

template<class T1,class T2>   //进行对showper来声明类模板函数
void showper(person<T1,T2> &p)
{
    std::cout << p.name << " " << p.age << std::endl;
}



template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age)
    {
        this->name = name;
        this->age = age;
    }
    //友元内部声明
    friend void showperson(person<T1,T2> &p)
    {
        std::cout << p.name << " " << p.age << std::endl;
    }

    //全局函数的类外实现
    friend void showper<>(person<T1,T2> &p);  //注意:在外部声明需要进行类模板参数初始化，但是该函数不是类模板类型，所以编译器会报错
    //解决方式，要将声明的函数为模板类型

    private:
    T1 name;
    T2 age;
};




// void test1()
// {
//     person<std::string,int> p("nn",100);
//     showperson(p);
// }


void test2()
{
    person<std::string,int> p("ss",100);
    showper(p);
}

int main(void)
{
    test2();
    return 0;
}

