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
    v1.push_back(7);
    v1.push_back(5);
    
    if(std::binary_search(v1.begin(),v1.end(),1))
    {
        std::cout << "find" << std::endl;
    }
    else
    {
        std::cout << "not" << std::endl;
    }
}


int main()
{
    test01();
    return 0;
}