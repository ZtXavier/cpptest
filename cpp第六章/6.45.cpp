#include<cctype>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::string;
using std::vector;

int get(vector<int>::iterator begin,vector<int>::iterator end){
    if(begin == end){
        return 0;
    }
    cout << *begin << endl;
    get(++begin,end);
    return 0;
}

int main(void){
    vector<int> a{1,2,3,4,5};
    get(a.begin(),a.end());            //迭代器类型
    return 0;
}
