#include"deivate.hpp"

void test()
{
    person<std::string,int>p("dad",50);
    p.showperson();
}

int main(void)
{
    test();
    return 0;
}