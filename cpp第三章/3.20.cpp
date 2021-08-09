#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
using std::vector;
int main(void){
    vector<int> n;
    int c;
    while(cin >> c)
    n.push_back(c);
    for(decltype(n.size())i = 0;i != n.size();i++){
        cout << n[i];
    }
    cout << endl;
    for(decltype(n.size())i = 0;i <= (n.size()-1)/2;i++){
        cout << n[i]+n[n.size()- 1 - i];
    }
    cout << endl;
    return 0;
}