#include<iostream>
#include<list>
#include<string>
#include<algorithm>

int main()
{
    std::string s1[] = {"aawf","eefad","eirjgrios","eefad"};
    std::list<std::string> l1;
    for(auto s : s1)
    {
        l1.push_back(s);
    }
    int num = std::count(std::begin(s1),std::end(s1),"eefad");
    std::cout << num << std::endl;
    return 0;
}