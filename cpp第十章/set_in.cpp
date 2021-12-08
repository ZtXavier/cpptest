#include<iostream>
#include<vector>
#include<algorithm>


//求两个容器的交集
//两个集合必须是有序序列，函数的最后一个参数为目标容器的begin()

void myprint(int v)
{
    std::cout << v <<" "; 
}

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    for(int i = 5;i < 14;i++)
    {
        v2.push_back(i);
    }
    std::vector<int> target;
    target.resize(std::min(v1.size(),v2.size()));
    //这里将返回遍历完的最后一个交集的迭代器
    std::vector<int>::iterator itend = std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),target.begin());
//     for_each(target.begin(),target.end(),myprint);
//      上面会将该容器内的所有数据打印出来
    for_each(target.begin(),itend,myprint);
    std::cout << std::endl;
 }

int main()
{
    test01();
    return 0;
}