#include<iostream>
#include<vector>
#include<map>

void add_kid(std::map<std::string,std::vector<std::string>> &famliy,std::string fname,std::string lname)
{
    if(famliy.find(fname) == famliy.end())
    {
        std::cout << "no first name" << std::endl;
        return ;
    }
    famliy[fname].push_back(lname);
}

void add_famliy(std::map<std::string,std::vector<std::string>> &famliy,std::string fname)
{
    if(famliy.find(fname) == famliy.end())
    {
        famliy[fname] = std::vector<std::string> ();         //匿名函数的开辟空间
    }
}


int main()
{
    std::map<std::string,std::vector<std::string>> famliy;
    add_kid(famliy,"Alan","jerry");
    add_famliy(famliy,"Alan");
    add_kid(famliy,"Alan","jerry");

    for(auto &a : famliy)
    {
        std::cout << a.first <<": ";
        for(auto &c : a.second)
        std::cout << c << " ";
        std::cout << std::endl;
    }
    return 0;
}