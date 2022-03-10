#include<iostream>
#include<vector>
#include<algorithm>

class panduan
{
    public:
        bool operator()(int val)
        {
            return val > 5;
        }
};

void test01()
{
    std::vector<int> v1;
    for(int i = 0;i < 5;i++)
    {
        v1.push_back(i);
    }
    std::vector<int>::iterator it = find_if(v1.begin(),v1.end(),panduan());
    if(it == v1.end())
    {
        std::cout << "没有找到!" << std::endl;
    }
    else
    {
        std::cout << "找到大于5" << std::endl;
    }

}

class person
{
    public:
        person(){};
        person(std::string name,int age)
        {
            this->name = name;
            this->age = age;
        }
        // 重载 == 
        bool operator()(person &p)
        {
            return p.age > 11;
        }
        std::string name;
        int age;
};

void test02()
{
    std::vector<person> v1;
    person p1("aaa",12);
    person p2("bbb",13);
    person p3("ccc",14);
    person p4("ddd",15);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);

    std::vector<person>::iterator it = find_if(v1.begin(),v1.end(),person());
    if(it == v1.end())
    {
        std::cout << "没有找到!" << std::endl;
    }
    else
    {
        std::cout << "找到" << it->age << it->name << std::endl;
    }
    
}

int main()
{
   // test01();
   test02();
    return 0;
}