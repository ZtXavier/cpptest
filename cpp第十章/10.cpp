#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>


int main()
{
    // std::vector<int> vec = {1,2,3,24,41,42,92};
    // int val = 42;
    // std::vector<int>::iterator it = vec.begin();
    // auto result = find(it,vec.end(),val);
    // std::cout << *result << std::endl;
    // int ia[] = {12,152,34,4534,231};
    // int val = 34;
    // int *result = std::find(std::begin(ia),std::end(ia),val);  //可以利用指针进行计算
    // std::cout << *result << std::endl;


    // std::vector<int> vec = {1,2,3,24,41,42,92};
    // int sum  = std::accumulate(vec.begin(),vec.end(),0);//求和函数，第三个参数为求和之前的初始值
    std::vector<std::string> vt = {"wdadfef","gefeda","oooo"};
    std::string sum  = std::accumulate(vt.begin(),vt.end(),std::string("love"));  //在这里定义的初始化字符串需要是string类型，否则会报错
    std::cout << sum << std::endl;
    return 0;
}