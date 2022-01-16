#include<iostream>
#include<vector>
#include<map>
#include<string>


int main()
{
    std::string f_n;
    std::string l_n;
    std::string birthday;
    std::map<std::string,std::vector<std::pair<std::string,std::string>>> kid;

    while(std::cin >> f_n >> l_n >> birthday)
    {
        kid[f_n].push_back(make_pair(l_n,birthday));
    }

    for(auto &f : kid)
    {
        std::cout << f.first << " ";
        for(auto &s : f.second)
        {
            std::cout << s.first << " " << s.second << std::endl;
        }
    }
    return 0;
}