#include<iostream>
#include<string>
#include<fstream>
#include<vector>

void in(std::string t,std::vector<std::string> &file)
{
    std::fstream input(t);
    std::string b;
    if(input.good())
    {
        while(input >> b)
        {
            file.push_back(b);
        }
    }
}


int main(void)
{
    std::vector<std::string> file;
    std::string  filename;
    std::cin >> filename;
    in(filename,file);
    for(auto a : file)
    std::cout << a << std::endl;
    return 0;
}