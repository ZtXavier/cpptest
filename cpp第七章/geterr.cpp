#include<cctype>
#include<iostream>
#include<string>
#include<climits>

unsigned long facgeterr(unsigned short num)
{
    unsigned long sum = 1;
    unsigned long max = ULONG_MAX;
    for(int i = num;i >= 1;i--){
        sum *= i;
        max /= i;
    }
    if(max < 1)
    {
        throw std::runtime_error("输入的数过大，超出范围....\n");
    }else
    {
        return sum;
    }
}


int main(void)
{
    unsigned short num,num2;
    // std::cin.ignore(100,'\n'); //清除缓冲区100个字符，遇到'\n'结束
    std::cin >> num;
    // std::cin >> num2;
    std::cout << num << '\n' << num2 << std::endl;
    try
    {
        unsigned long ret = facgeterr(num);
        std::cout << num << "! = " << ret << std::endl;
    }
    catch(std::runtime_error err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}