#include<iostream>
#include<cctype>
#include<string>

class Book
{
    public:
    Book() = default;
    Book(std::string s):bookNo(s),nums_sold(0),revenue(0.0){}
    Book(std::string s,int nums,double rev) : bookNo(s),nums_sold(nums),revenue(rev) {}


    private:
    std::string bookNo;
    int nums_sold = 0;
    double revenue = 0.0;
};