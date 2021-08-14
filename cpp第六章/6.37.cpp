#include<cctype>
#include<iostream>
#include<string>
using namespace std;
using std::string;
typedef string arr[10];
//或using arr = string[10];
arr(&func(string (&str)[10]));           //(1)

auto func2(arr & str) -> string(&)[10];  //(2)

string as[10];
decltype(as) &func3(string(&str)[10]);   //(3)