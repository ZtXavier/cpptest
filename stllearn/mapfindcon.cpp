#include<iostream>
#include<map>

void mapprint(std::map<int,int> &m)
{
    std::cout << m.size() << std::endl;
    for(std::map<int,int>::iterator it = m.begin();it != m.end();it++)
    {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
}


void test01()
{
    std::map<int,int> m1;
    m1.insert(std::pair<int,int>(1,10));
    m1.insert(std::make_pair(2,20));
    m1.insert(std::map<int,int>::value_type(3,30));
    m1[4] = 40;
    m1[5] = 50;
    mapprint(m1);
    std::map<int,int>::iterator it = m1.find(3);
    std::cout << (*it).second << std::endl;
    int num = m1.count(6);
    std::cout << num << std::endl;
}



int main()
{
    test01();
    return 0;
}