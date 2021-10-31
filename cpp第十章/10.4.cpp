#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>


int main()
{
    std::vector<double> v1 = {1.24123,13.231,423.5909};
    double n = std::accumulate(v1.begin(),v1.end(),0);//会出现错误，小数点后面的数全部省略
    std::cout << n << std::endl;
    return 0;
}