#include<iostream>
#include<cctype>
#include<vector>
#include<string>
using namespace std;
using std::string;
using std::vector;
int &get(int *a,int i){
    return a[i];
}
int main(void){
    int ia[10];
    for(int i = 0;i != 10;++i)
    get(ia,i) = i;
    for(int i:ia)
    cout << i << " ";
    cout << endl;
    return 0;
}
