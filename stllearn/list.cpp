#include<list>
#include<iostream>


void listprint(std::list<int> &l)
{
    for(std::list<int>::iterator it = l.begin();it != l.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}



void test01()
{
    std::list<int> l1;
    for(int i = 0;i < 4;i++)
    {
        l1.push_back(i);
    }
    listprint(l1);
    std::list<int> l2(l1.begin(),l1.end());
    listprint(l2);
    std::list<int> l3(10,4);
    listprint(l3);

    std::list<int> l4;
    l4.assign(3,99);
    listprint(l4);
    l3.swap(l1);
    listprint(l1);
    listprint(l3);
}



int main()
{
    test01();
    return 0;
}
