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

template <class T>
class My_operating
{
    public:
        T operator()(T val)
        {
            return val;
        }
};

void test01()
{
    std::vector<int> v1;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }


    std::vector<int> v2;
    v2.resize(v1.size());

    std::transform(v1.begin(),v1.end(),v2.begin(),My_operating<int>());
    std::for_each(v2.begin(),v2.end(),my_print());
    std::cout << std::endl;
}



int main()
{
    test01();
    return 0;
}