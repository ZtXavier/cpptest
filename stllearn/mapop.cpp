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
    //插入的四种方式
    //利用pair来插入
    m1.insert(std::pair<int,int>(1,20));
    //利用make_pair来插入
    m1.insert(std::make_pair(2,10));
    //第三种利用定义来插入
    m1.insert(std::map<int,int>::value_type(3,50));
    //利用下标索引来插入
    m1[4] = 40;
    mapprint(m1);

    m1.erase(2);
    mapprint(m1);
    // m1.erase(m1.begin(),m1.end());
    m1.clear();
    mapprint(m1);
}


int main()
{
    test01();
    return 0;
}