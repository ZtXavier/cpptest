#include<iostream>
#include<vector>
#include<algorithm>

class myPrint
{
    public:
    void operator ()(int val)
    {
        std::cout << val << " ";
    }
};


void test01()
{
    std::vector<int>v1;
    std::vector<int>v2;

    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+20);
    }
    swap(v1,v2);

    for_each(v1.begin(),v1.end(),myPrint());
    
}




int main()
{
    test01();
    return 0;
}