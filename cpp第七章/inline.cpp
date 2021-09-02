#include<iostream>
#include<string>
#include<cctype>

class Sales_data
{
    public:
    double price_avg() const;
    private:
    unsigned int units_sold;
    double revenue;
};

inline double Sales_data::price_avg() const //内联函数的定义，函数少于10行就可以定义来提高效率
{
    if(units_sold)
    return revenue / units_sold;
    else
    return 0;
}



