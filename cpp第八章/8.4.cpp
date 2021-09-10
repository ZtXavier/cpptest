#include<iostream>
#include<string>
#include<vector>
#include<fstream>



void in(std::string &filename,std::vector<std::string> &file)
{
    std::ifstream input(filename);
    std::string b;
    if(input)
    {
        while(std::getline(input,b))
        {
            file.push_back(b);
        }
    }
};



int main(void)
{
    std::string filename;
    std::vector<std::string> file;
    std::cout << "输入文件名" << std::endl;
    std::cin >> filename;
    in(filename,file);
    for(auto a : file)
    std::cout << a << std::endl;
    return 0;
}
