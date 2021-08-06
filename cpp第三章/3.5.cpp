#include<iostream>
using namespace std;
using std::string;
int main(void){
    string s1,s2;
    int loop = 3;
    while(loop){
        cin >> s1;
        s2 += s1 + " ";
        loop--;
    }
    cout << s2 << endl;
    return 0;
}