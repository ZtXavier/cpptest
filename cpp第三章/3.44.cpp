#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;
int main(void){
    int ia[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // typedef int s;
    // for(s (*p)[4] = begin(ia);p != end(ia);p++)
    // for(int *q = begin(*p); q != end(*p); q++)
    // cout << *q << " ";
    // cout << endl;
    for(auto c = begin(ia);c != end(ia);c++)
    for(auto q = begin(*c);q != end(*c);q++)
    cout << * q << " ";
    cout << endl;
    return 0;
}