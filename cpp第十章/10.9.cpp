#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


void elimDup(std::vector<std::string> &sw)
{
    std::sort(sw.begin(),sw.end());
    auto end_unique = std::unique(sw.begin(),sw.end());
    sw.erase(end_unique,sw.end());
}

int main()
{
    std::vector<std::string> v1 = {"string","opening","loading","ease","string","string","opposite"};
    elimDup(v1);
    for(auto i : v1)
    std::cout << i << std::endl;
    return 0;
}