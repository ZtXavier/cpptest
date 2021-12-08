#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<numeric>

void test01()
{
    std::vector<int> v;
    v.resize(10);
    fill(v.begin(),v.end(),5);
    for(auto &i : v)
    {
        std::cout << i << std::endl;
    }


}

int main()
{
    test01();
    return 0;
}