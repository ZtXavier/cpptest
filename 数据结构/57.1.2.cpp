#include<iostream>
#include<vector>

void My_reverse(std::vector<int> &n)
{
    int i,j,tmp;
    i = 0;
    j = n.size() - 1;
    while(i < j)
    {
        n[i] ^= n[j];
        n[j] ^= n[i];
        n[i] ^= n[j];
        i++;
        j--;
    }
}



int main(void)
{
    int i;
    std::vector<int> p;
    while(std::cin >> i)
    {
        p.push_back(i);
    }
    for(auto a : p)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    My_reverse(p);
    for(auto &a : p)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}