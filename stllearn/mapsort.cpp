#include<iostream>
#include<map>



class Mycompare
{
    public:
    bool operator()(const int a,const int b) const
    {
        return a > b;
    }
};

void mapprint(std::map<int,int,Mycompare> &m)
{
    std::cout << m.size() << std::endl;
    for(std::map<int,int,Mycompare>::iterator it = m.begin();it != m.end();it++)
    {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
}


void test01()
{
    std::map<int,int,Mycompare>m1;
    for(int i = 10;i > 0;i--)
    {
        m1[i] = i*10-i*2;
    }
    mapprint(m1);
}


int main()
{
    test01();
    return 0;
}