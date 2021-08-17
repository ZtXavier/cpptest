#include<cctype>
#include<iostream>
#include<string>

int main(void)
{
    int cnt = 10;
    int *x = new int[cnt];
    for(int i = 0;i < cnt;i++)
    {
        x[i] = i;
    }
    for(int i = 0;i < cnt;i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    delete[] x;
    cnt = 5;
    x = new int[cnt];
    for(int i = 0;i < cnt;i++)
    {
        x[i] = i;
    }
    for(int i = 0;i < cnt;i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
