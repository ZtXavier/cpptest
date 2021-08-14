#include<iostream>
#include<cctype>
#include<vector>
#include<string>
using namespace std;
using std::string;
using std::vector;
int put(vector<int> c,vector<int>::size_type num){
    if(num == 0){
    cout << c[num] << endl;
    return 0;
    }
    else{
    put(c,num - 1);
    cout << c[num] << endl;
    return 0;
    }
}
int main(void){
    vector<int> index{1,2,3,4,5,6,7,8};
    put(index,index.size()-1);
    return 0;
}