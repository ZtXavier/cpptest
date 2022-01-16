#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

int main()
{
    std::string str;
    int i;

    std::vector<std::pair<std::string,int>> v1;
    
    while(std::cin >> str >> i)
    {
        v1.push_back(make_pair(str,i));
        v1.emplace_back(str,i);               //因为emplace_back里面的元素可以是args创建的元素
        v1.push_back(std::pair<std::string,int> (str,i));      //匿名函数来进行创建
    }
    return 0;
}