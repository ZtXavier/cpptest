#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
using std::string;

string::size_type reset(int &i){
    while(i > 0){
        i--;
    }
    return 5;
}
int main(void){
    int a = 10;
    int ret = reset(a);
    cout << a << " " << ret << endl;
    return 0;
}