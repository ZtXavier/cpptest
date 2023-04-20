#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    string in;
    cin >> in;
    string ret;
    int n = in.size();
    int min = INT32_MAX; 
    unordered_map<char,int> mp;
    for(int i = 0; i < n; ++i) {
        ++mp[in[i]];
    }
    for(int i = 0; i < n; ++i) {
        if(mp[in[i]] == 1 && i < min) {
            min = i;
        } 
    }
    cout << min << endl;
    return 0;
}