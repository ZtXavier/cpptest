#include"Sales_data.h"


Sales_data& Sales_data::Combine(const Sales_data &rhs)
{
    this->revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
}

std::istream& read(std::istream &is,Sales_data &item) //解释为什么面向流要用引用，由于io类型不可复制，只能通过引用来传参
{
    double price  = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price*item.units_sold;
    return is;
}

std::ostream& print(std::ostream &os,Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
    << item.avg_price();
    return os;
}

void add_data(Sales_data &litem,Sales_data &ritem)
{
    litem.Combine(ritem);
}