#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
using std::string;
int main(void){
    // vector<int> num(10,1);
    // for(auto &c : num)
    // c *= 2;
    // for(auto i : num)
    // cout << i << " ";
    // cout << endl;
    vector<string> ss;
    string s1 = {"welcome"};
    ss.push_back(s1);
    // for(auto &c : ss)
    // c = "dd";
    for(auto it = ss.begin();it != ss.end();++it)
    *it = "dawd";
    for(auto i : ss)
    cout << i << " ";
    cout << endl;
    return 0;
}