#include<iostream>
#include<string>
#include<set>

class person
{
    public:
    person(std::string name,int age)
    {
        this->Name = name;
        this->age = age;
    }
    std::string Name;
    int age;
};

class My_Compare
{
public:
    bool operator()(const person &p1,const person &p2) const
    {
        return p1.age > p2.age;
    }
};


void setprint(std::set<person,My_Compare> &l)
{
    for(std::set<person,My_Compare>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << (*it).Name << (*it).age << std::endl;
    }
}

void test01()
{
    std::set<person,My_Compare> s1;
    person p1("adf",123);
    person p2("adtwf",53);
    person p3("wf",43);
    person p4("rtywf",973);
    person p5("aogf",324);
    person p6("jjtjhf",684);


    s1.insert(p1);
    s1.insert(p2);
    s1.insert(p3);
    s1.insert(p4);
    s1.insert(p5);
    s1.insert(p6);

    setprint(s1);

}

int main()
{
    test01();
    return 0;
}


