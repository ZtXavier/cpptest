#include<iostream>
#include<tuple>

std::tuple<int,double,std::string> f()
{
    return std::make_tuple(1,2.3,"456");
}


int main()
{
    int x;
    double y;
    std::string z;
    std::tie(x,y,z) = f();
    std::cout << x << " " <<  y  << " "<< z << " ";
    return 0;
}