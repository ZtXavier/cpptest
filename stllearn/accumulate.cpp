#include<algorithm>
#include<iostream>
#include<vector>
#include<numeric>
class myPrint
{
    public:
        void operator()(int val)
        {
            std::cout << val << " ";
        }
};


void test01()
{
    std::vector<int> v1;
    std::vector<int> v2(10,1);

    // 也可用fill算法
    for_each(v2.begin(),v2.end(),myPrint());
    std::cout <<std::endl;
//     for(int i = 0;i < 5;i++)
//     {
//         v1.push_back(i);
//     }
//    // 第三个参数是起始数值
//     std::cout << std::accumulate(v1.begin(),v1.end(),0) << std::endl;
}

int main(void)
{
    test01();
    return 0;
}