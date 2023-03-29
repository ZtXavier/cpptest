#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    vector<int> v;
    for(int i = 0;i < 10;i++) {
        v.push_back(i);
    }
    vector<int> v1 = {1,2,3,4,5};
    // v1.clear();
    vector<int> (v1).swap(v);
    std::cout << v.size();
    for(int i = 0;i < v1.size();++i) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl; 
    return 0;
}