#include<iostream>
#include<vector>
#include<cctype>
#include<string>


void test01()
{
    std::vector<int> p1,p2,p3,p4,p5;
    for(int i = 0;i < 5;i++)
    {
        p1.push_back(i);
        p2.push_back(i+1);
        p3.push_back(i+2);
        p4.push_back(i+3);
        p5.push_back(i+4);
    }

    std::vector<std::vector<int>> P;
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);
    P.push_back(p4);
    P.push_back(p5);

    for(std::vector<std::vector<int>>::iterator it = P.begin();it != P.end();it++)
    {
        for(std::vector<int>::iterator pit = (*it).begin();pit != (*it).end();pit++)
        {
            std::cout << (*pit) << " ";
        }
        std::cout << std::endl;
    }
}


int main(void)
{
    test01();
    return 0;
}