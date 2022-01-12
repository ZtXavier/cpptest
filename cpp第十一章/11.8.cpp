#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

int main()
{
    std::vector<std::string> words;
    std::string word;
    while(std::cin >> word && word != "EOF") 
    {
        if(find(words.cbegin(),words.cend(),word) == words.cend())
        {
            words.push_back(word);
        }
    }
    for(auto &w : words)
    {
        std::cout << w << std::endl;
    }
    return 0;
}