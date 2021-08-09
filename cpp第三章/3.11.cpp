#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    const string s = "keep out!";
    //for(auto &c : s)   //不合法，不可向只读形参赋值
    //c = 'x';
    return 0;
}