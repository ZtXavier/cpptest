#include<iostream>
#include<string>


void my_findnum(std::string &s)
{
    int pos = 0;
    std::string snum = {"0123456789"};
    int n;
    while((n = s.find_first_of(snum,pos)) != std::string::npos)
    {
        std::cout << s[n] << std::endl;
        pos = n+1;
    }
}

void my_findword(std::string &s)
{
    int pos = 0;
    std::string snum = {"0123456789"};
    int n;
    while((n = s.find_first_not_of(snum,pos)) != std::string::npos)
    {
        std::cout << s[n] << std::endl;
        pos = n+1;
    }
}


int main()
{
    std::string s1 = {"ab2c3d7R4E6"};
    my_findnum(s1);
    my_findword(s1);
    return 0;
}