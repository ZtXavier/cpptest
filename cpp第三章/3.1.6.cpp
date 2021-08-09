#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
int main(void){
    vector<int> num(11,0);
    for(int i = 0; i <= 10;i++)
    num.push_back(i);
    cout << "the sum of num is " << num.size() << "\n";
    for(auto c : num)
    cout << c << " ";
    cout << endl;
    return 0;
}