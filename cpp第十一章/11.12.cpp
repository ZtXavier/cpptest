#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    int num;
    std::string word;


    std::vector<std::pair<std::string,int>> vt;
    while(std::cin >> word >> num)
    {
        vt.emplace_back(word,num);
    }

    for_each(vt.begin(),vt.end(),[](const std::pair<std::string,int> &p){std::cout << p.first << " " << p.second << std::endl;});
    return 0;
}