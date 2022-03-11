#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>



void test01()
{
    std::vector<int> v1;
    for(int i = 0;i < 5;i++)
    {
        v1.push_back(i);
    }
   // 第三个参数是起始数值
    std::cout << std::accumulate(v1.begin(),v1.end(),0) << std::endl;
}

int main(void)
{
    test01();
    return 0;
}