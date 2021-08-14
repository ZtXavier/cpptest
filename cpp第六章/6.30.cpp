#include<iostream>
#include<vector>
#include<cctype>
#include<string>
using namespace std;
using std::string;
using std::vector;

bool str_subrange(const string &str1,const string &str2){
    if(str1.size() == str2.size())
    return str1 == str2;    //正确，==运算符返回布尔值
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for(decltype(size)i = 0;i != size;i++){
        if(str1[i] != str2[i])
        return;                      //编译器无法识别出错误
    }
}
int main(void){
    return 0;
}