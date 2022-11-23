#include<iostream>
#include<map>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
    unordered_map<string,int> um(5);
    um.emplace("123",6);
    um.emplace("124",7);
    um.emplace("125",8);
    um.emplace("90",66);
    unordered_map<string,int>::iterator it = um.begin();
    um.emplace("123",6);
    um.emplace("124",7);
    um.emplace("125",8);
    um.emplace("90",66);
    const string *key_ptr = &(um.find("123")->first);
    return 0;
}