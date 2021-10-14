#include<iostream>
#include<list>
#include<string>

class person
{
public:
    person(std::string name,int age,int height)
    {
        this->Name = name;
        this->age = age;
        this->height = height;
    }
    std::string Name;
    int height;
    int age;
};


bool my_cmp(person &a,person &b)
{
    if(a.age == b.age)
    {
        return a.height < b.height;
    }
    return a.age > b.age;
}

void listprint(std::list<person> &l)
{
    for(std::list<person>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << "姓名为：" << (*it).Name << "年龄为：" << (*it).age << "身高为:" << (*it).height << std::endl;
    }
}

void test01()
{

    std::list<person> l1;
    person p1("zz",20,150);
    person p2("ll",50,110);
    person p3("xx",70,160);
    person p4("hh",30,200);
    person p5("bb",90,180);
    person p6("oo",30,140);
    person p7("dd",30,170);
    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.push_back(p5);
    l1.push_back(p6);
    l1.push_back(p7);
    listprint(l1);
    std::cout << "-------------------------------" << std::endl;
    l1.sort(my_cmp);
    listprint(l1);
}



int main()
{
    test01();
    return 0;
}