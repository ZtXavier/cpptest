#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string>


int main(void)
{
    std::ifstream out;
    std::string line,word;
    std::vector<std::string> info;
    out.open("FILE.txt",std::ifstream::in);
    if(!out.is_open())
    {
        std::cerr <<  "无法打开文件" << std::endl;
    }
    while(getline(out,line))
    {
        std::cout << "读取的信息为:" << line << std::endl;
        info.push_back(line);
    }
    out.close();
    for(auto i : info)  //单个进行遍历
    {
        std::istringstream sintemp(i);
        while(sintemp >> word)
        std::cout << word << std::endl;
    }
    return 0;
}