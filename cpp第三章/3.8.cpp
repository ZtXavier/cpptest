#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    string s,s1;
    while(cin >> s)
        for(auto c : s)
        if(!ispunct(c))
        // s1 += c;
        cout << c << endl;
        return 0;
}