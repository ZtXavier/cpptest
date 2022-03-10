#include<iostream>
#include<vector>
#include<algorithm>

void myPrintf(int val)
{
    std::cout << val << " " ;
}

void test01()
{
    std::vector<int> v1;
    std::vector<int> v2;

    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+2);
    }

    std::vector<int> target;
    target.resize(v1.size() + v2.size());
    std::merge(v1.begin(),v1.end(),v2.begin(),v2.end(),target.begin());

    std::for_each(target.begin(),target.end(),myPrintf);
    std::cout << std::endl;
}



int main()
{
    test01();
    return 0;
}