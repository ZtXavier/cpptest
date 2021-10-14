#include<iostream>
#include<list>


/*
insert(pos,elem)    //在pos处插入elem元素
insert(pos,n,elem)  //在pos处插入n个elem元素
insert(pos,beg,end) //在pos处插入beg到end的区间
remove(elem)        //删除容器中所有与elem值相同的元素
 */

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
    for(int i = 0;i < 9;i++)
    {
        l1.push_back(i);
    }
    listprint(l1);
    l1.push_front(99);
    l1.pop_back();
    l1.pop_front();
    listprint(l1);
    std::list<int> l2;
    l2.push_back(50);
    l2.push_back(50);
    l2.push_back(50);
    listprint(l2);
    std::list<int>::iterator it = l2.begin();
    std::list<int>::iterator i = l1.end();
    l1.insert(i,l2.begin(),l2.end());
    listprint(l1);
    l1.remove(50);
    listprint(l1);
}


int main()
{
    test01();
    return 0;
}