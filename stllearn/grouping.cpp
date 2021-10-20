#include<iostream>
#include<map>
#include<vector>
#include<string>

#define C 0
#define M 1
#define Y 2


class worker
{
public:
    std::string Name;
    int money;
};

void createworker(std::vector<worker> &w)
{
    srand((unsigned int)time(NULL));
    std::string nameSeed = "ABCDEFGHIJ";
    for(int i = 0;i < 10;i++)
    {
        std::string name = "员工: ";
        name += nameSeed[i];
        int m = rand()%10001 + 3000;
        worker w1;
        w1.Name = name;
        w1.money = m;
        w.push_back(w1);
    }
}

void setgroup(std::vector<worker> &w,std::multimap<int,worker> &m)
{
    srand((unsigned int)time(NULL));
    for(std::vector<worker>::iterator it = w.begin();it != w.end();it++)
    {
        int n = rand()%3;
        m.insert(std::make_pair(n,(*it)));
    }
}


void printgroup(std::multimap<int,worker> &m)
{
    std::multimap<int,worker>::iterator pos = m.begin();
    int count = m.count(C);
    int index = 0;
    for(;pos != m.end() && index < count;pos++,index++)
    {
        std::cout << (*pos).second.Name << " 工资：" <<(*pos).second.money << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    count = m.count(M);
    index = 0;
    for(;pos != m.end() && index < count;pos++,index++)
    {
        std::cout << (*pos).second.Name << " 工资：" <<(*pos).second.money << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    count = m.count(Y);
    index = 0;
    for(;pos != m.end() && index < count;pos++,index++)
    {
        std::cout << (*pos).second.Name << " 工资：" <<(*pos).second.money << std::endl;
    }
}





int main()
{
    std::vector<worker> mk;
    createworker(mk);
    std::multimap<int,worker> mw;
    setgroup(mk,mw);
    printgroup(mw);
    return 0;
}