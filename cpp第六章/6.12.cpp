#include<cctype>
#include<iostream>
using namespace std;
using std::string;
int func (int &i,int &c){
    i = i ^ c;            //交换两个数的值
    c = c ^ i;
    i = i ^ c;
    return 0;
}
int main(void){
    int i,c;
    cin >> i >> c;
    func(i,c);
    cout << i << " " << c << endl;
    return 0;
}