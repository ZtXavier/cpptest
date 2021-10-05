#include<iostream>
#include<string>
#include<vector>

void If_huiwen(std::string &s1)
{
    int num = s1.size() - 1;
    for(int i = 0,j = num;i < j;i++,j--)
    {
        if(s1[i] != s1[j])
        {
            std::cout << "it is not a huiwen number!" << std::endl;
            return;
        }
    }
    std::cout << "true" << std::endl;
    return;
}



int main(void)
{
    std::string s1 = "abdba";
    std::string s2 = "ageghewe";
    // while(std::cin >> )
    If_huiwen(s1);
    If_huiwen(s2);
    return 0;
}