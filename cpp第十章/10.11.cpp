#include<iostream>
#include<vector>
#include<string>
#include<algorithm>



class isShorter
{
public:
    bool operator()(const std::string &s1,const std::string &s2)
    {
        return s1.size() < s2.size();
    }
};



void test01(void)
{
    std::vector<std::string> v1 = {"adwad","eshrd","p","htdsdci","rgo","wf","o"};
    std::sort(v1.begin(),v1.end(),isShorter());
    for(auto i : v1)
    {
        std::cout << i << std::endl;
    }
}



int main()
{
    test01();
    return 0;
}