#include<iostream>
#include<vector>
#include<string>

class person
{
public:
    person(std::string name,int age)
    {
        this->name = name;
        this->age  = age;
    }

    int age;
    std::string name;
};


void test01()
{
    person p1("ss",1001);
    person p2("rs",1001);
    person p3("ys",1001);
    person p4("ts",1001);
    person p5("ls",1001);

    std::vector<person*> per;
    per.push_back(&p1);
    per.push_back(&p2);
    per.push_back(&p3);
    per.push_back(&p4);
    per.push_back(&p5);

    for(std::vector<person *>::iterator it = per.begin();it != per.end();it++)
    {
        std::cout << (*it)->name << " " << (*it)->age << std::endl;
    }
}

int main(void)
{
    test01();
    return 0;
}