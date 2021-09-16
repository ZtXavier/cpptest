#include<iostream>
#include<string>
#include<vector>
#include<cctype>
#include<fstream>
#include<sstream>


struct personinfo
{
    std::string name;
    std::vector<std::string> phones;
};

int main(void)
{
    std::string line,word;
    std::vector<personinfo> people;
    std::ifstream out;
    out.open("numinof.txt",std::ifstream::in);
    if(!out.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        getchar();
        return 0;
    }
    while(out >> line)
    {
        personinfo per;
        std::istringstream record(line); //将记录绑定到读入的line
        record >> per.name;
        while(record >> word)         //用单个的字符流读取数据时当读到空格会直接返回
            per.phones.push_back(word);
        people.push_back(per);
    }
    for(auto &a : people)
    {
        std::cout << a.name << " " << std::endl;
        for(auto &b : a.phones)
        {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}