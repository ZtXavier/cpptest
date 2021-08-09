#include<iostream>
#include<cctype>
using namespace std;
using std::string;
int main(void){
    int m[7] = {1,2,3,4,5,6,7};
    int (&a)[sizeof(m)/sizeof(int)] = m;
    for(auto c : a){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}