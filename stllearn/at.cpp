#include<iostream>
#include<vector>



void test01(void)
{
    std::vector<int> v1;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    for(int i = 0;i < 10;i++)
    {
        std::cout << v1.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "the first elem is " << v1.front() << std::endl;
    std::cout << "the last elem is " << v1.back() << std::endl;
}


int main()
{
    test01();
    return 0;
}