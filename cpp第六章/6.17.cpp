#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;

bool computer2(char &str2){
    str2 = toupper(str2);
    return true;
}

bool computer(string &str1){
    for(auto &c : str1){
        if(islower(c)){
            computer2(c);
        }
    }
    return true;

}

int main(void){
    string str = {"asdWDF"};
    computer(str);
    cout << str << endl;
    return 0;
}