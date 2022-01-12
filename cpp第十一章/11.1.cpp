#include<iostream>
#include<map>
#include<string>
#include<set>

int main()
{
    // std::map<std::string,size_t> word_count;
    // std::string word;
    // while(std::cin >> word && word != "EOF")
    // {
    //     ++word_count[word];
    // }
    // for(auto &w : word_count)
    // {
    //     std::cout << w.first << " " << w.second << std::endl;
    // }

    std::map<std::string,size_t> word_count;
    std::set<std::string> exclue = {"The","But","And","Or","An","A","the","but","and","or","an","a"};
    std::string word;
    while(std::cin >> word && word != "EOF")
    {
        if(exclue.find(word) == exclue.end())
        ++word_count[word];
    }
    return 0;
}