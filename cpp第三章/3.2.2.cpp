#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    const string hexdigits = "0123456789ABCDEF"; //可能的十六进制数
    cout << "Enter a seriers of numbers between 0 and 15"
    << " separated by spaces.Hit Enter when finished: "
    << endl;
    string result;           //用于保存十六进制的字符串
    string::size_type n;     //用于保存从输入流读取的数
    while(cin >> n){
        if(n < hexdigits.size()){
            result = result + hexdigits[n] + " ";
        }
    }
    cout << "Your hex number is: " << result << endl;
    return 0;
}