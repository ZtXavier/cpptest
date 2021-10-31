#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> v1 = {1,2,3,4,0,1,1,5,6,7,8};
    // int num = std::count(v1.begin(),v1.end(),1);        //两种模式进行遍历
    int num  = std::count(std::begin(v1),std::end(v1),1);
    std::cout << num << std::endl;
    return 0;
}