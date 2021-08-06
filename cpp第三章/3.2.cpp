#include<iostream>
using namespace std;
using std::string;
int main(void){
    string s1,s2;
    //getline(cin,s1);
    cin >> s1;
    cin >> s2;
    if(s1.size() > s2.size())
    cout<< s1 << endl;
    else if(s1.size() < s2.size()){
        cout << s2 << endl;
    }else{
        cout << "same" << endl;
    }
    return 0;
}