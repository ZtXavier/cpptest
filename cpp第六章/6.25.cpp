#include<iostream>
#include<cctype>
#include<vector>
using namespace std;
using std::string;
using std::vector;
int main(int argc,char **argv){
    if(argc <= 1)
    cout << "please enter two elem" << endl;
    else{
        string str;
        for(int i = 1;i < argc;i++)
        str =str + argv[i] + " ";
        cout << str << endl;
    }
    return 0;
}