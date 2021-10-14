#include<set>
#include<iostream>



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
    std::set<int>s1;                //set容器不支持重复元素，且插入元素会自动排序，输入元素只可使用insert()函数
    s1.insert(20);
    s1.insert(10);
    s1.insert(50);
    s1.insert(30);
    s1.insert(20);
    setprint(s1);
}



int main()
{
    test01();
    return 0;
}