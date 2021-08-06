#include<iostream>
using namespace std;
using std::string;
int main(void){
    string s1,s2;
    //getline(cin,s1);
    cin >> s1;
    cin >> s2;
    if(s1 >= s2)
    cout<< s1 << endl;
    else{
        cout << s2 << endl;
    }
    return 0;
}