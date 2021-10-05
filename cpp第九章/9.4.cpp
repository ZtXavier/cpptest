#include<iostream>
#include<cctype>
#include<vector>
#include<list>


void test01()
{
    int a[] = {0,1,1,2,3,5,8,13,21,55,89};
    int num = sizeof(a)/sizeof(int);
    
    std::vector<int> pr(num);
    std::list<int> lr(num);

    for(int i = 0;i < num;i++)
    {
        pr.push_back(a[i]);
        lr.push_back(a[i]);
    }
    std::vector<int>::iterator vt = pr.begin();
    std::list<int>::iterator lt = lr.begin();
    while(vt != pr.end())
    {
        if((*vt) % 2 == 0)
        {
            vt = pr.erase(vt);
        }
        else
        {
            vt++;
        }
    }
    while(lt != lr.end())
    {
        if((*lt) % 2 == 1)
        {
            lt = lr.erase(lt);
        }
        else
        {
            lt++;
        }
    }

    for(auto &i : pr)
    {
        std::cout << i << std::endl;
    }
    std::cout << "*********" << std::endl;

    for(auto &i : lr)
    {
        std::cout << i << std::endl;
    }
}





int main(void)
{
    test01();
    return 0;
}