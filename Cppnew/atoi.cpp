#include<iostream>
#include<vector>
#include<numeric>

int main() {
    std::vector<int> v1(9,1);
    // iota 会在初始化大小的vector变量中从第三个参数开始递增的填充一个连续的数
    std::iota(v1.begin(),v1.end(),0);
    for(auto &a : v1){
        std::cout << a << std::endl;
    }
    return 0;
}