#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>


// void find_word(const std::string &s1)
// {
//     std::string str("bdfghijklpqty");
//     std::string ret;
//         auto pos = s1.find_first_of(str);
//         if(pos == std::string::npos)
//         {
//             std::cout << s1 << std::endl;
//         }
// }


// int main(int argc,char *argv[])
// {
//     std::ifstream input(argv[1]);

//     std::string line,word;

//     while(getline(input,line))
//     {
//         std::istringstream in(line);
//         while(in >> word)
//         {
//             find_word(word);
//         }
//     }
//     return 0;
// }



void word_find(std::string &s1)
{
    std::string str("bdfghijklpqty");
    std::string word;
    auto pos = s1.find_first_of(str);
    if(pos == std::string::npos)
    {
        std::cout << s1 << std::endl;
    }
}


int main(int argc,char *argv[])
{
    std::ifstream input(argv[1]);
    std::string line;
    std::string word;
    while(getline(input,line))
    {
        std::istringstream in(line);
        while(in >> word)
        {
            word_find(word);
        }
    }
    return 0;
}