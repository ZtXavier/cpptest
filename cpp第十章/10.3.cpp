#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>


int main()
{
    // bool s;
    // std::vector<std::string> v1 ={"awdadwa","a"};
    // std::vector<std::string> v2 = {"awdadw","a"};
    // s = std::equal(v1.begin(),v1.end(),v2.begin());
    // std::cout << s << std::endl;
    std::vector<int> v1 = {1,2,3,4};
    int sum = std::accumulate(v1.begin(),v1.end(),0);
    std::cout << sum << std::endl;
    return 0;
}