#include<cctype>
#include<iostream>
#include<string>
using namespace std;
using std::string;
constexpr int isshorter(int i = 24){
    return i*60;
}
int main(void){
    cout << isshorter(18) << endl;
    return 0;
}