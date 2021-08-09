#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
int main(void){
    vector<int> v2;  //空的vector对象
    for(int i = 0;i != 10; i++)
    v2.push_back(i);          //容器内的元素不可直接以输出流输出出
    for(auto c : v2)
    cout << c << endl;
    return 0;
}