#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    string s1 = "xadcawdwedfafa";
    // for(int i = 0;i < s1.size(); i++){
    //     s1[i] = 'X';
    // }
    for(auto &c : s1)    //变量类型改为char没有影响
    c = 'X';
    cout << s1 << endl;
    return 0;
}