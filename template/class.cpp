#include<iostream>
#include<string>

template<class N,class A>
class person
{
    public:
    person(N name,A age)
    {
        this->name = name;
        this->age = age;
    }
    void showdata()
    {
        std::cout << name << " " << age << std::endl;
    }
    private:
    int age;
    std::string name;
};

void test()
{
    //person p("老子"，1000);
    person<std::string,int> p("老子",999);
    p.showdata();
}




int main(void)
{
    test();
    return 0;
}