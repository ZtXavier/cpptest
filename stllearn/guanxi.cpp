#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>


//内建函数关系对象 实现关系运算判断等

class myCompare
{
    public:
    bool  operator ()(int v1,int v2)
    {
        return v1 > v2;
    }

};


void test01()
{
   std::vector<int> v1;
   v1.push_back(1);
   v1.push_back(3);
   v1.push_back(2);
   v1.push_back(5);
   v1.push_back(4);

   for(std::vector<int>::iterator it = v1.begin();it != v1.end();it++)
   {
       std::cout <<*(it) << " ";
   }
   std::cout << std::endl;

    // std::sort(v1.begin(),v1.end(),myCompare());
    // greater 作为系统提供的内建仿函数
    /*
    greater_equal  大于等于
    less_equal       小于等于 
     */
     std::sort(v1.begin(),v1.end(),std::greater<int>());
    for(std::vector<int>::iterator it = v1.begin();it != v1.end();it++)
   {
       std::cout <<*(it) << " ";
   }
   std::cout << std::endl;
}




int main()
{
    test01();
    return 0;
}