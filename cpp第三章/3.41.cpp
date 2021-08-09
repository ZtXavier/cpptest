#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
using std::string;
using std::vector;
int main(void){
    int a[5] = {1,2,3,4,5};
    vector<int> s(a,a+5);
    for(auto c : s)
    cout << c  << " ";
    cout << endl;
    return 0;
}