#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
int main(void){
    vector<int> ivec;
    ivec.push_back(242);
    //ivec[0] = 242;   //很容易会这样写，是错误的
    cout << ivec[0] << endl;
    return 0;
}