#include<iostream>
#include<cctype>
#include<string>
#include<ctime>
#include<vector>

void radret(std::vector<int> &p,int len)
{
    for(int i = 0 ;i < len;i++)
    {
        p[i] = random()%99;
    }
}




int main(void)
{
    std::vector<int> p(10,0);
    int len = 10;
    radret(p,len);
    for(auto i = 0;i < len;i++)
    {
        std::cout << p[i] << std::endl;
    }
    return 0;
}