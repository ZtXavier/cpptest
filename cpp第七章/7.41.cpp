#include<iostream>
#include<string>
#include"Sales_data.h"

//委托构造函数，执行顺序先执行被委托的函数，再执行委托函数内部的语句

int main(void)
{
    Sales_data total;
    Sales_data total2("1-2",0,0);
    Sales_data total3("",0,0);
    Sales_data total4("s");
    Sales_data total5(std::cin);
    return 0;
}