#include<iostream>
#include<string>
#include<map>
#include<algorithm>

int main()
{
    std::map<std::string,size_t>  count;
    std::cout << "input" << std::endl;

    std::string word;
    while(std::cin >> word && word != "EOF")
    {
        if(isupper(word[0]))
        {
            word[0] = tolower(word[0]);
        }
        if(ispunct(word[word.size()-1]))
        {
            word.pop_back();
        }
        ++count[word];
    } 
    for(auto &a : count)
    {
        std::cout << a.first << " occurs " << a.second << " " <<  ((a.second > 1) ? "times" : "time") << std::endl;
    }
    return 0;
}