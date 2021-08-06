#include<iostream>
using namespace std;
using std::string;
int main(void){
    string s1,s2;
    while(cin >> s1){  //解决循环坑1.ctrl+D (在上一个字符串输入完按回车后再用)2.ctrl+Z (在输入完字符串后使用ctrl+Z在按回车退出,但是会出错)
        s2 += s1 + " ";
    }
    cout << s2 << endl;
    return 0;
}