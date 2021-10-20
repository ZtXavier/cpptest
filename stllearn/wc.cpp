#include<iostream>
#include<vector>
#include<algorithm>

class mypd
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
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    // mypd jd; //也可以创建一个对象来填入find_if的参数中
    // std::vector<int>::iterator it = std::find_if(v1.begin(),v1.end(),jd);
    //一般使用匿名对象，利用仿函数中重载（）的方式来进行传递
    std::vector<int>::iterator it = std::find_if(v1.begin(),v1.end(),mypd());
    if(it == v1.end())
    {
        std::cout << "not find" << std::endl;
    }
    else
    {
        std::cout << "find " << (*it) << std::endl;
    }
}


class mypd2
{
public:
    explicit mypd2(int x) :num(x) {}
    bool operator()(int val)
    {
        return val > num;
    }
    int num;
};


void test02()
{
    std::vector<int> v2;
    for(int i = 0;i < 10;i++)
    {
        v2.push_back(i);
    }
    // mypd jd; //也可以创建一个对象来填入find_if的参数中
    // std::vector<int>::iterator it = std::find_if(v1.begin(),v1.end(),jd);
    //一般使用匿名对象，利用仿函数中重载（）的方式来进行传递
    std::vector<int>::iterator it = std::find_if(v2.begin(),v2.end(),mypd2(4));
    if(it == v2.end())
    {
        std::cout << "not find" << std::endl;
    }
    else
    {
        std::cout << "find " << (*it) << std::endl;
    }
}



int main()
{
    test01();
    return 0;
}