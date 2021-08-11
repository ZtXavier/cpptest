#include<iostream>
#include<cctype>
using namespace std;
int func(int c){
    int ap = 1;
    int num = c;
    static size_t ctr = 0;  //函数结束该值不会被释放
    while(c > 1){
        ap *= c;
        c--;
    }
    cout << num << "! = " << ap << endl;
    return ctr++;
}

int main(void){
    int i,j;
    // cin >> i >> j;
    while(cin >> i){
    int ret = func(i);
    // int ret = func(j);
    cout << "调用了函数func()" << ret
    << "次" << endl;
    }
    return 0;
}