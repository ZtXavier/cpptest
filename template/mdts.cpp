#include<iostream>
#include<string>
#include<vector>
//实现对数组进行怕排序
//规则从大到小
//选择排序
//测试 char int数组

template<class T>
void test(T &a)
{
    int num = a.size();
    int temp;

    for(int i = 0;i < num - 1;i++)
    {
        for(int j = i + 1;j < num;j++)
        {
            if(a[i] > a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

int main(void)
{
    int i;
    std::string s;
    std::vector<int> a;

    std::cout << "string" << std::endl;
    std::cin >> s;
    std::cout << s << std::endl;


    while(std::cin >> i)
    {
        a.push_back(i);
    }
    for(auto &s : a)
    {
        std::cout << s << " " ;
    }
    std::cout << std::endl;

    //测试
    test(a);
    for(auto &s : a)
    {
        std::cout << s << " " ;
    }
    std::cout << std::endl;
    test(s);
    std::cout << s << std::endl;
}