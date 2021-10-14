#include<iostream>
#include<vector>

void test01()
{
    std::vector<int> v1;
    int *p = NULL;
    int num = 0;
    // v1.reserve(10000); //该函数起到了对于一个容器的预留空间作用
    //如果你所需要的空间大于该空间，则会扩容，否则不会
    for(int i = 0;i < 10000;i++)
    {
        v1.push_back(i);
        if(p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    std::cout << num << std::endl;

}



int main()
{
    test01();
    return 0;
}