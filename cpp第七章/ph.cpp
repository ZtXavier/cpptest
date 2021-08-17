#include<iostream>
#include<cctype>
#include<string>

int *init(int num)
{
    int *p = new int[num];    //动态内存才能返回，栈内存不可返回，会被释放
    for(int i = 0;i < num;i++)
    p[i] = i;
    return p;
}

int main(void)
{
    int cnt;
    int *p;
    std::cout << "请输入初始化的数量：" << std::endl;
    std::cin >> cnt;
    p = init(cnt);
    for(int i = 0;i < cnt;i++)
    std::cout << p[i] << " ";
    std::cout << std::endl;
    delete[] p;
    return 0;
}