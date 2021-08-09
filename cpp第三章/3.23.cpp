#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;
int main(void){
    int i = 0;
    int a[10];
    vector<int> n{1,2,3,4,5,6,7,8,9,10};
    for(auto c = n.begin();c != n.end();c++){
        a[i]  = (*c)*2;
        i++;
    }
    n.clear();
    for(i = 0;i < 10;i++){
        n.push_back(a[i]);
    }
    for(auto c = n.begin();c != n.end();c++){
    cout << *c << " ";
    }
    cout << endl;
    return 0;
}