#include<vector>
#include<iostream>
#include<cctype>
using namespace std;
using std::string;
using std::vector;
int main(void){
    string st={"acfhijklmnopq"};
    char sought;
    cin >> sought;
    auto beg = st.begin();
    auto end = st.end();
    auto mid = st.begin() + (st.size()-1)/2;
    while(mid != end && *mid != sought){
        if(sought < *mid){
            end = mid;
        }else{
            beg = mid + 1;
        }
        mid = beg + (end - beg)/2;
    }
    cout << *mid << endl;
    return 0;
}