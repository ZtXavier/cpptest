#include<iostream>
#include<string>
#include"Sales_data.h"
using namespace std;
int main(void){
    Sales_data data1,data2;
    double price = 0;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    if(data1.bookNo == data2.bookNo){
        price = data1.revenue + data2.revenue;
        cout<< "1 and 2 sum is " << price << endl;
        return 0;
    }else{
        cout<< "node must be same!"  << endl;
        return -1;
    }
}