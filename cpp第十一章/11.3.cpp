#include<iostream>
#include<map>
#include<string>

int main()
{
    std::map<std::string,size_t> count;
    std::string word;
    std::cout << "input" << std::endl;

    while(std::cin >> word && word != "EOF")
    {
        ++count[word];
    }
    for(auto &a : count)
    {
        std::cout << a.first << " occurs " << a.second << " " <<  ((a.second > 1) ? "times" : "time") << std::endl;
    }
    return 0;
}
