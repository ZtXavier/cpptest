#include<iostream>
#include<string>
#include<vector>



void my_change(std::string &s1,std::string &oldval,std::string &newval)
{
    int len = oldval.size();

    if(s1.size() < len)
    return;

    std::string::iterator it = s1.begin();  //先将s1的迭代器赋值给it

    while((s1.end() - it) >= len)             //这里判断的是如果s1的长度小于s_old的长度，则退出循环，因为无法匹配到对应的长度
    {
        std::string::iterator it_old = oldval.begin();
        std::string::iterator temp = it;
        for(;it_old != oldval.end();it_old++,temp++)
        {
            if(*temp != *it_old)            //利用双指针判断，只要判断不等于则直接退出
            {
                break;
            }
        }
        if(it_old == oldval.end())
        {
            std::string::iterator it_new = newval.begin();
            s1.replace(it,temp,it_new,newval.end());              //将9.42中的erase和insert用replace代替
        }
        it++;
    }
}

int main()
{
    std::string s1 = "tho thru awfthodfawthru";
    std::string s_old = "thru";
    std::string s_new = "throught";
    my_change(s1,s_old,s_new);
    std::cout << s1 << std::endl;
    return 0;
}