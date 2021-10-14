#include<iostream>
#include<set>

void setprint(std::set<int> &s1)
{
    for(std::set<int>::iterator it = s1.begin();it != s1.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "大小为：" << s1.size() << std::endl;
}

void test01()
{
    //注意：set函数不可以使用reserve来预留空间
    std::set<int> s1;
    s1.insert(20);
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(90);
    s1.insert(70);
    setprint(s1);
    std::set<int> s2;
    s2.insert(200);
    s2.insert(400);
    s2.insert(300);
    setprint(s2);
    std::cout << "交换后：" << std::endl;
    s1.swap(s2);
    setprint(s1);
    setprint(s2);
    s1.erase(s1.begin(),s1.end());
    s2.clear();
    setprint(s1);
    setprint(s2);
}



int main()
{
    test01();
    return 0;
}