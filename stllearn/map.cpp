#include<iostream>
#include<map>


void mapprint(std::map<int,int> m)
{
    for(std::map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
}





void test01()
{
    //map插入时会按照key值排序
    std::map<int,int> m1;
    m1.insert(std::pair<int,int>(1,10));             //在对map进行操作时使用pair对组进行创建
    m1.insert(std::pair<int,int>(2,20));
    m1.insert(std::pair<int,int>(3,60));
    m1.insert(std::pair<int,int>(4,70));
    mapprint(m1);
}



int main()
{
    test01();
    return 0;
}
