#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;
int main(void){
    int a;
    vector<int> num;          //在迭代器中的int类型存在数组里
    while(cin >> a)
    num.push_back(a);
    for(auto it = num.begin();it != num.end();++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}