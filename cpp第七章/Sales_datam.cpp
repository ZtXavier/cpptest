#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include"Sales_data.h"

int main(int argc,char *argv[])
{
    std::cout << "请输入交易记录(ISBN,售出总数，售出价格)" << std::endl;
    Sales_data total;
    if(read(std::cin,total))
    {
        Sales_data trans; //读取第二条记录
        while(read(std::cin,trans))
        {
            if(total.isbn() == trans.isbn())
            {
                add_data(total,trans);
            }
            else
            {
                //输出旧书号的记录
                print(std::cout,total) << std::endl;
            }
        }
        print(std::cout,total) << std::endl;
    }
    else
    std::cerr << "没有交易记录..." << std::endl;
    return 0;
}