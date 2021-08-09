#include<iostream>
#include<cctype>
using namespace std;
int main(void){
    int a[5] = {1,2,3,4,5};
    int *p = &a[4];
    *p = 0;
    for(auto c : a)
    cout << c << " ";
    cout << endl;
    return 0;
}