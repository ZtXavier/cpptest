#include<iostream>
#include<cctype>

#define MAX 1000

typedef struct static_list
{
    int num;
    int passwd;
    int cur;
}list;




int main(void)
{
    int num,passwd;
    std::cout << "请输入人数和初始密码" << std::endl;
    std::cin >> num;
    std::cin >> passwd;
    list head[num];
    int k;
    int stp = num;
    for(int i = 0;i < num - 1;i++)
    {
        head[i].num = i + 1;
        head[i].cur = i + 1;
        std::cout << "请输入第" << i+1 << "个人的passwd" << std::endl;
        std::cin >> head[i].passwd;
    }
    head[num - 1].cur = 0;
    int l = passwd;
    while(1)
    {
        if(stp == 1)
        {
            
            break;
        }
        for(int i = 0;i < l%num;i++)
        {
            k = head[k].cur;
        }
    }


}