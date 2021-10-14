#include<iostream>
#include<set>




//有2两种定义方式，既可以使用类，也可以使用结构体
struct cmp
{
    bool operator() (const int &a,const int &b) const
    {
        return a > b;
    }
};

class My_Compare
{
public:
    bool operator() (const int &a,const int &b) const   //定义时必须使用const类型
    {
        return a > b;
    }
};

void setprint(std::set<int,My_Compare> &l)
{
    for(std::set<int,My_Compare>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void test01()
{
    std::set<int,My_Compare> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    setprint(s1);
    for(std::set<int,My_Compare>::iterator it = s1.begin();it != s1.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}



