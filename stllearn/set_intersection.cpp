#include<iostream>
#include<vector>
#include<algorithm>

// 求两个集合的交集
class my_print
{
    public:
   void operator ()(int val)
    {
        std::cout << val << " ";
    }
};


void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+2);
    }
    std::vector<int> t;
    // 新的容器首先初始化大小
    t.resize(std::min(v1.size(),v2.size()));
    std::vector<int>::iterator itend = std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),t.begin());
    std::for_each(t.begin(),itend,my_print());
    std::cout << std::endl;
        
}


int main()
{
    test01();
    return 0;
}