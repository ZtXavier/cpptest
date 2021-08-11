#include<cctype>
#include<iostream>
#include<vector>
using namespace std;
using std::string;
int compare_(int a,int *p){
    return a > *p ? a : *p;
}


int main(void){
    int i = 5;
    int a = 10;
    int *p = &a;
    cout << compare_(i,p) << endl;
    return 0;
}