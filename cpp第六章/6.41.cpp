#include<cctype>
#include<iostream>
#include<string>
using namespace std;
using std::string;
inline bool isshorter(const string &s1,const string &s2){
    return s1.size() < s2.size();
}
int main(void){
    string s1,s2;
    s1 = {"dawdad"};
    s2 = {"wwww"};
    cout << isshorter(s1,s2) << endl;
    return 0;
}