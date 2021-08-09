#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
using std::string;
using std::vector;
int main(void){
    vector<int> s{1,2,3,4,5,6,7,8};
    size_t i = 0;
    size_t len = s.size();
    int a[len];
    for(auto c : s)
    a[i++] = c;
    for(decltype(s.size())i = 0;i < s.size();i++)
    cout << a[i] << " ";
    cout << endl;
    return 0;
}