#include"deivate.h"

//problem:由于类模版中的成员函数创建时机是在调用阶段，导致分文件编写时链接不到
//solution:1.直接包含.cpp文件 2.将.cpp文件和.h文件写到一起，取名后缀改为.hpp


template<class T1,class T2>
person<T1,T2>::person(T1 name,T2 age)
{
    this->name = name;
    this->age = age;
}

template<class T1,class T2>
void person<T1,T2>::showperson()
{
    std::cout << name << " " << age << std::endl;
}

