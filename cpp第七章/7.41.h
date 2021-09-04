#ifndef BDC5E9DD_1285_4B44_9C0F_BFEB40CB77F4
#define BDC5E9DD_1285_4B44_9C0F_BFEB40CB77F4

#ifndef CH6_H_INCLUDE
#define CH6_H_INCLUDE
#include<iostream>
#include<string>

  
class Sales_data
{
    public:
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){std::cout<<"2"<<std::endl;}
    Sales_data() : Sales_data("",0,0){std::cout << "4" << std::endl;}
    Sales_data(std::string s) : Sales_data(s,0,0) {std::cout << "5" << std::endl;}
    Sales_data(std::istream &is) : Sales_data()
    {
        read(is,*this);
        std::cout << "6" << std::endl;
    }

    std::string isbn() const {return bookNo;}
    Sales_data &Combine(const Sales_data &);
    friend std::istream& read(std::istream &,Sales_data &);
    friend std::ostream& print(std::ostream &,Sales_data &);
    friend void add_data(Sales_data &,Sales_data &);

    private:
    double avg_price() const
    { return units_sold ? revenue/units_sold : 0;}
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};



#endif



#endif /* BDC5E9DD_1285_4B44_9C0F_BFEB40CB77F4 */
