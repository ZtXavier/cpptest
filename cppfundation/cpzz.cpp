#include<iostream>
#include<string>
#include<regex>


int main()
{
    std::string fnames[] = {"foo.txt","bar.txt","test","a0.txt","AAA.txt"};
    std::regex txt_regex("([a-z]+)\\.txt");
    for(const auto &fname : fnames)
    {
        // 匹配成功返回1,否则返回0
        std::cout << fname << ": " << std::regex_match(fname,txt_regex) << std::endl; 
    }
    std::smatch base_match;
    for(const auto &fname : fnames)
    {
        if(std::regex_match(fname,base_match,txt_regex))
        {
            if(base_match.size() == 2)
            {
               // std :: smatch 的 第 一 个 元 素 匹 配 整 个 字 符 串 
                // std :: smatch 的 第 二 个 元 素 匹 配 了 第 一 个 括 号 表 达 式
                std::string base = base_match[1].str();
                std::cout << "sub 0: " << base_match[0].str() << std::endl;
                std::cout << "sub 1:" << base << std::endl;
            }
        }
    }
    return 0;
}