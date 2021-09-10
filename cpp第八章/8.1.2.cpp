#include<iostream>

std::istream &put(std::istream& s)
{
    int st;
    while(s >>st)
    std::cout << st << std::endl;
    s.clear();                          //对流置位并使流有效
    return s;
}

int main(void)
{
    std::istream &is  = put(std::cin);
    std::cout << is.rdstate() << std::endl; //该函数返回流的状态
    return 0;
}