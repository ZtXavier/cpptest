#include<iostream>
#include<vector>
#include<algorithm>

void test01()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);
    v1.push_back(2);

    std::cout << std::count(v1.begin(),v1.end(),2) << std::endl;
}


class Person
{
    public:
    Person(){};
    Person(std::string name,int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator == (const Person &p)
    {
        return p.age == age;
    }
    int age;
    std::string name;
};

void test02()
{
    std::vector<Person> v1;
    Person p1("刘备",35);
    Person p2("关",35);
    Person p3("张",35);
    Person p4("操",40);

    Person find("诸",35);
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);

    int num = std::count(v1.begin(),v1.end(),find);
    std::cout << "同岁的有" << num << "个" << std::endl;

}









int main()
{
    //test01();
    test02();
    return 0;
}