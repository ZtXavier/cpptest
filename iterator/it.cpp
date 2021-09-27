#include<iostream>
#include<vector>
#include<algorithm>

void my_print(int val)
{
    std::cout << val << std::endl;
}



int main(void)
{
    int n = 10;
    std::vector<int> a;
    while(n > 0)
    {
        a.push_back(n);
        n--;
    }

    for_each(a.begin(),a.end(),my_print);           //其参数为起始指针和回调函数

    return 0;
}