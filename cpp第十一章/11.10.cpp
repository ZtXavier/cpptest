#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<sstream>




int main()
{
    std::map<std::string,std::list<int>> count;
    std::string word;
    int num = 1;
    while(getline(std::cin,word))
    {
        std::istringstream in(word);
        while(in >> word)
        count[word].push_back(num);
        num++;
    }
    for(auto &a : count)
    {
        std::cout << a.first <<  ":";
        std::list<int>::iterator tep = a.second.begin();
        while(tep != a.second.end())
        {
            std::cout << *tep++ << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}