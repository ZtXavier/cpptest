#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
int p(int i,int j);

using f2 = int(*)(int,int);
using f3 = decltype(p);
using f4 = decltype(p)*;
typedef int (*f5)(int,int);
typedef decltype(p) *f6;

int add(int a,int b){
    return a + b;
}
int sub(int a,int b){
    return a - b;
}
int mul(int a,int b){
    return a * b;
}
int divi(int a,int b){
    return b != 0 ? a / b : 0;
}
int main(void){
    vector<f2> p{add,sub,mul,divi};
    vector<f3*> p2;
    vector<f4> p3;
    vector<f5> p4;
    vector<f6> p5;
    for(auto c : p)
    cout << c(2,4) << endl;
    return 0;

}