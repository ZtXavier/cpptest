#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

class Sales_data
{
    public:
    friend std::istream &read(std::istream &,Sales_data &);
    friend std::ostream &print(std::ostream &os,const Sales_data &item);
    Sales_data() = default;    //默认构造函数
    Sales_data(const std::string &s):bookNo(s){}
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n) {}
    Sales_data(std::istream &is){read(is,*this);}

    std::string isbn() const {return bookNo;}
    Sales_data &combine(const Sales_data&);
    double avg_price()const;

    private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&,const Sales_data&);
std::ostream &print(std::ostream&,const Sales_data&);
std::istream &read(std::istream&,Sales_data&);


double Sales_data::avg_price() const
{
    if(units_sold)
    return revenue/units_sold;
    else
    return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read(std::istream &is,Sales_data &item)
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os,const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// Sales_data::Sales_data(std::istream &is)
// {
//     read(is,*this);
// }




int main(int argc,char *argv[])
{
    std::ifstream in("FILE.txt");
    std::ofstream out("FILE.txt",std::ofstream::app); //若不设置std::ofstream::app则会隐式的将文件删除
    Sales_data total;
    if(read(in,total))
    {
        Sales_data trans;
        while(read(in,trans))
        {
            if(total.isbn() == trans.isbn())
            total.combine(trans);
            else
            {
                print(std::cout,total) << std::endl;
                print(out,total) << std::endl;
                total = trans;
            }
        }
        print(std::cout,total) << std::endl;
        print(out,total) << std::endl;
    }
    else
    {
        std::cerr << "No data?" <<std::endl;
    }
    return 0;
}