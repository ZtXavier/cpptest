#ifndef PERSON_H
#define PERSON_H
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



#endif /* A24A40D2_E783_47CD_8E4F_FAF875938C5B */
