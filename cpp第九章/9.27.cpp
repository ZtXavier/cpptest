#include<iostream>
#include<forward_list>
#include<list>

void test01()
{
    std::forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int>::iterator forls = fl.before_begin(),forl = fl.begin();
    while(forl != fl.end())
    {
        if(*forl % 2)
        {
            forl = fl.erase_after(forls);
        }
        else
        {
            forls = forl;
            forl++;
        }
    }
    for(auto &i : fl)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



int main(void)
{
    test01();
    return 0;
}