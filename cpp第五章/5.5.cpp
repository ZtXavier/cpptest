#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::vector;
using std::string;
int main(void){
    int i = 0;
    int grade;
    string str[20];
    vector<string> scr{"E","D","C","B","A","A+"};
    while(cin >> grade && i != 20){
        // if(grade < 60)
        // str[i] = scr[0];
        // else{
        //     str[i] = scr[(grade-50)/10];
        // }
        grade < 60 ? str[i] = scr[0]:str[i] = scr[(grade-50)/10];
        i++;
    }
    for(auto c : str)
    cout << c << " ";
    cout << endl;
    return 0;
}