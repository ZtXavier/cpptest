#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>


void test01()
{
    std::vector<bool> v1;
    v1.push_back(true);
    v1.push_back(false);
    v1.push_back(true);

    for(std::vector<bool>::iterator it = v1.begin();it != v1.end();it++)
    {
        std::cout << *(it)  <<  " ";
    }
    std::cout << std::endl;

    std::vector<bool> v2;
    v2.resize(v1.size());       //给v2开创v1.size()的数据空间
    std::transform(v1.begin(),v1.end(),v2.begin(),std::logical_not<bool>());

    for(std::vector<bool>::iterator it = v2.begin();it != v2.end();it++)
    {
        std::cout << *(it)  <<  " ";
    }
    std::cout << std::endl;
}




int main()
{
    test01();
    return 0;
}