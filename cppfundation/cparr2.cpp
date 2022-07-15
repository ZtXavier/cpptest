#include<iostream>
#include<string>
#include<array>
#include<algorithm>



 void foo(int *p,int len)
{
        return;
}


int main()
{
    std::array<int,4> arr = {1,2,3,4};
    for(auto &a : arr)
    {
        std::cout << a << std::endl;
    }
    std::cout << arr.empty() << std::endl;
    std::cout << arr.size() << std::endl;

    std::sort(arr.begin(),arr.end(),[](int a,int b){return b < a;});
    for(auto &a : arr)
    {
        std::cout << a << std::endl;
    }
    // 数组大小必须是常量表达式
    constexpr int len = 4;
    std::array<int,len> arr1 = {1122,43,434,435};

   
    //两种传参方式 c风格的接口
    foo(&arr[0],arr.size()); 
    foo(arr.data(),arr.size());
    // arr1.data()是返回数组的首地址
    std::cout << *arr1.data() << std::endl;
    return 0;
}