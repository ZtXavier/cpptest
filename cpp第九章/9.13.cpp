#include<iostream>
#include<vector>
#include<string>
#include<list>

int main(void)
{
    std::list<int> a(10,1);
    std::list<int>::iterator it = a.begin(),ed = a.end();
    std::vector<double> p(it,ed);                  //利用迭代器作为参数来初始化
    for(auto &i : p)
    {
        std::cout << i << std::endl;
    }
    return 0;
}