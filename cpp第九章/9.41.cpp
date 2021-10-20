#include<iostream>
#include<string>
#include<vector>


int main()
{
    
    std::vector<char> v1 = {'l','o','a','d'};
    std::string s1(v1.begin(),v1.end());
    // for(int i = 0;i < v1.size();i++)
    // {
    //     s1 += v1[i];
    // }
    std::cout << s1 << std::endl;
    return 0;
}


//9.42  如果我知道我的string每次只能读取一个字符并且最少要读取100个字符，我需要先预留reverve(100)个空间