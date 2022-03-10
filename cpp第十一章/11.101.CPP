#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include<algorithm>
#include<utility>


// bool compare_Isbn(const Sales_data &lhs,const Sales_data &rhs)
// {
//      return Ihs.isbn() < rhs.isbn();
// } 

//  multiset<Sales_data,decltype(compare_Isbn)*> bookstore(compare_Isbn);

// 将这个函数用函数指针的方法作为参数


namespace skj
{
    int i =1;
    int rand = 2;
}


using namespace skj;

int main()
{
    // std::multiset<Sales_data,bool(*)(const Sales_data &,const Sales_data &)>
    // bookstore([](const Sales_data &Ihs,const Sales_data *rhs) {return Ihs.isbn() < rhs.isbn();});        //使用lambda 来进行bookstore的方法进行初始化

    int i = 0;       // namespace 中的变量会被隐藏
    printf("%d",i);
    return 0;
}