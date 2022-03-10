#include<iostream>
#include<vector>
#include<algorithm>



void test01()
{
    std::vector<int> v1;
    for(int i = 0;i < 5;i++)
    {
        v1.push_back(i);
    }
    v1.push_back(3);
    v1.push_back(1);
    std::sort(v1.begin(),v1.end());
    // 查找相邻重复的元素
    std::vector<int>::iterator it = std::adjacent_find(v1.begin(),v1.end());

    if(it == v1.end())
    {
        std::cout << "not find" << std::endl;
    }
    else
    {
        std::cout << "find" << (*it) << std::endl;
    }
        
}


int main()
{
    test01();
    return 0;
}