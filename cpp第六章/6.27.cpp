#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;
using std::initializer_list;
using std::vector;
int add(initializer_list<int> a){
    int ret = 0;
    for(auto c : a)
        ret += c;
    return ret;
}
int main(void){
    initializer_list<int> lis{1,2,3,4,5,6,7,8};
    cout <<  add(lis);
    cout << endl;
    return 0;
}