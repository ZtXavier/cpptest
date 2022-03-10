#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>


void myPrintf(int val)
{
    std::cout << val << " ";
}

void test01()
{

    //需要加入时间种子
    srand((unsigned int)time(NULL));
    std::vector<int> v1;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    std::random_shuffle(v1.begin(), v1.end());
    for_each(v1.begin(),v1.end(),myPrintf);
    std::cout << std::endl;
}

int main()
{
    test01();
    return 0;
}