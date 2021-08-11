#include<iostream>
#include<cctype>
using namespace std;
int fact(int index){
    int val = 1;
    if(index == 0)
    return 1;
    while(index > 1){
        val *= index;
        index--;
    }
    return val;
}
int main(void){
    int i;
    cin >> i;
    cout << i << "! = " << fact(i) << endl;
    return  0;
}