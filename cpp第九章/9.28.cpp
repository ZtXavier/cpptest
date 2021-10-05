#include<iostream>
#include<vector>
#include<string>
#include<forward_list>


void in_list(std::forward_list<std::string> &l,std::string s1,std::string s2)
{
    std::forward_list<std::string>::iterator it = l.before_begin() , rl = l.begin();
    if(*rl != s1)
    {
        l.insert_after(it,s1);
        rl = it;
        it++;
        l.insert_after(it,s2);
    }
    else
    {
        l.insert_after(rl,s2);
    }
    for(std::forward_list<std::string>::iterator atd = l.begin();atd != l.end();atd++)
    {
        std::cout << *atd << " ";
    }
    std::cout << std::endl;

}


void test01()
{
    std::string s1 = "I",s2 = "love",s3 = "love you";
    std::forward_list<std::string> per(1);
    std::forward_list<std::string> per2;
    std::forward_list<std::string>::iterator a = per2.before_begin();
    per2.insert_after(a,s1);

    in_list(per,s1,s2);
    in_list(per2,s1,s3);

}


int main(void)
{
    test01();
    return 0;
}