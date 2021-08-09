#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
using std::vector;
using std::string;
int main(void){
    string text;
    vector<string> tx;
    // while(cin >> text){
        text = {"some spring"};
        for(auto it = text.begin();it != text.end()&&!isspace(*it);it++){
            *it = toupper(*it);
        }
            tx.push_back(text);   //字符串一次全部输入完
    // }
    for(auto c = tx.begin();c != tx.end();c++)
    cout << *c;
    cout << endl;
    return 0;
 }