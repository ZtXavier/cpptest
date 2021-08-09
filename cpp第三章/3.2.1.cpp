#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    string s("hello world!!!");
    decltype(s.size()) punct_cnt = 0;
    for(auto c : s)
    if(ispunct(c))
    ++punct_cnt;
    cout << punct_cnt << " punctuation chararcters in " << s << endl;
    return 0;
}