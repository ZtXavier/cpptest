#include<iostream>
#include<algorithm>
#include<list>

void listprint(std::list<int> &l)
{
    for(std::list<int>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool my_cmp(int a,int b)
{
    return a > b;
}

void test01()
{
    std::list<int>l1;
    l1.push_back(20);
    l1.push_back(10);
    l1.push_back(60);
    l1.push_back(40);
    l1.push_back(90);
    l1.push_back(80);
    listprint(l1);
    l1.reverse();
    listprint(l1);
    l1.sort();
    listprint(l1);
    l1.sort(my_cmp);  //这里使用my_cmp伪函数来进行比较大小的升降的模式改变
    listprint(l1);
    //注意：这里算法必须使用该容器中定义的函数，不可使用标准库中的算法函数，因为数据结构不匹配

}


int main()
{
    test01();
    return 0;
}