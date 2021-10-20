#include<iostream>
#include<string>



void my_input(std::string &s,std::string &sq,std::string &sh)
{
    // s.insert(0,sq,0);
    // s.insert(s.size(),sh,0);
    std::string::iterator it = s.begin();
    std::string::iterator qt = sq.begin();
    std::string::iterator ht = sh.begin();
    it = s.insert(it,qt,sq.end());
    it = s.insert(s.end(),ht,sh.end());
    std::cout << s << std::endl;
}

int main()
{
    std::string s1 = {"geafawddwd"};
    std::string sq = {"Mr."};
    std::string sh = {"JR"};
    my_input(s1,sq,sh);
    return 0;
}