#include<iostream>
#include<set>

void setprint(std::set<int> &s1)
{
    for(std::set<int>::iterator it = s1.begin();it != s1.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void test01()
{
    std::set<int> s1;
    s1.insert(50);
    s1.insert(20);
    s1.insert(30);
    s1.insert(70);
    s1.insert(40);
    setprint(s1);
    int num = s1.count(20);                    //因为set容器中不可以有重复的数字，所以值返回零或一
    std::cout << num << std::endl;
    std::set<int>::iterator it = s1.find(20);  //find方法会返回迭代器类型
    std::cout << *it << std::endl;

}



int main()
{
    test01();
    return 0;
}