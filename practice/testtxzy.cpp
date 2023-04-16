#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);
    string ret = "";
    for(int i = 0; i < s1.size(); ++i) {
        if(s2.find(s1[i]) == std::string::npos) {
            ret +=  s1[i];
        }
    }
    cout << ret << endl;
    return 0; 
}