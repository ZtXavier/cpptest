#include<cctype>
#include<iostream>
#include<string>

class Y;
class X
{
    Y *p = nullptr;
};

class Y
{
    X a;
};