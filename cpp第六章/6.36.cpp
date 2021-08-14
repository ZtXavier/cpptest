#include<cctype>
#include<iostream>
#include<string>
using namespace std;
using std::string;
string (&func(string (&str)[10]))[10];
//外层string(&func())[10]是对十个数组的引用的函数
//内层string(&str)[10]是对十个string 对象 的引用
