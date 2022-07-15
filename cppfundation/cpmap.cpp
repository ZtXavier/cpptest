#include<iostream>
#include<string>
#include<unordered_map>
#include<map>


int main()
{
    // 无序的，使用Hash实现，性能高
    std::unordered_map<int,std::string> m = {
        {1,"awd"},
        {2,"gthde"},
        {3,"rtdf"}
    };
    // 通过红黑树进行实现
    std::map<int,std::string> v = {
        {1,"lll"},
        {2,"kkk"},
        {3,"aaa"}
    };
    for(auto &m1 : m)
    {
        std::cout << m1.first << " : " << m1.second << std::endl;
    }
    std::cout << std::endl;
    for(auto &v1 : v)
    {
        std::cout << v1.first << " : " << v1.second << std::endl;
    }
    return 0;
}