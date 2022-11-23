#include<iostream>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
    unordered_map<string,int> um(5);
    cout << um.bucket_count() << endl;
    um.emplace("123",6);
    const string *key_ptr = &(um.find("123")->first);
    um.emplace("124",7);
    um.emplace("125",8);
    um.emplace("90",66);
    unordered_map<string,int>::iterator it = um.begin();
    string st = "1";
    for(int i = 0;i < 10000000;i++){
        um.insert({st + "1",6});

    }
    // um.rehash(10000);
    cout << it->first << endl;
    cout << *key_ptr << endl;
    return 0;
}