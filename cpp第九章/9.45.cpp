#include<iostream>
#include<string>



void my_input(std::string &s,std::string &sq,std::string &sh)
{
    std::string::iterator it = s.begin();
    std::string::iterator iq = sq.begin();
    it = s.insert(it,iq,sq.end());           //迭代器类型必须都为迭代器，或者使用s.insert(0,sq,0)该返回一个s的引用类型
    s.append(sh);
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