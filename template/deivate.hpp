#ifndef A4C6D4A5_DDED_4640_9264_14A6B82A2ECA
#define A4C6D4A5_DDED_4640_9264_14A6B82A2ECA

#include<iostream>
#include<string.h>

template<class T1,class T2>
class person
{
    public:
    person(T1 name,T2 age);
    void showperson();
    private:
    T1 name;
    T2 age;
};


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



#endif /* A4C6D4A5_DDED_4640_9264_14A6B82A2ECA */
