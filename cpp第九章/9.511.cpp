#include"9.511.h"



int main()
{
    std::string dates[] = {"Jan 1 2014","1/1/1990","January 1,1900"};
    try
    {
        for(auto s : dates)
        {
            date d1(s);
            std::cout << d1 << std::endl;
            // std::cout << s <<std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    return 0;
}