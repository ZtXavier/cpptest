#include<iostream>
#include<vector>
#include<algorithm>
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
    t.resize(v1.size()+v2.size());
    std::vector<int>::iterator itend = std::set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),t.begin());
    std::for_each(t.begin(),itend,my_print());
}


int main()
{
    test01();
    return 0;
}