#include<iostream>
#include<cctype>
#include<vector>

bool fine(std::vector<int> &n,int num)
{
    for(auto i = n.begin();i != n.end();i++)
    {
        if(*i == num)
        {
            return true;
        }
    }
    return false;
}




int main(void)
{
    int n;
    std::vector<int> a;
    std::cin >> n;
    a = {1,2,3,4,5,6,7,8,9};
    if(fine(a,n) == true)
    std::cout << n << " in the vector" << std::endl;
    if(fine(a,n) == false)
    std::cout << n <<  " not in the vector" << std::endl;
    return 0;
}
