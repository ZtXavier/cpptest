#include<iostream>
#include<string>


void test01(std::string &s1)
{
    if(s1.size() == 0)
    {
        std::cout << "为空数据" << std::endl;
        return ;
    }
    int m = 256;
    int top = -1;
    char a[m];
    for(auto &i : s1)
    {
        switch(i)
        {
            case '(':
            case '[':
            case '{':   a[++top] = i;
                        break;

            case ')':   if(top <= -1)
                        {
                            std::cout << "error1" << std::endl;
                            return;
                        }
                        if(a[top] == '(')
                        {
                            top--;
                        }
                        break;

            case ']':   if(top <= -1)
                        {
                            std::cout << "error1" << std::endl;
                            return;
                        }
                        if(a[top] == '[')
                        {
                            top--;
                        }
                        break;
            case '}':   if(top <= -1)
                        {
                            std::cout << "error1" << std::endl;
                            return;
                        }
                        if(a[top] == '{')
                        {
                            top--;
                        }
                        break;
            default:
                    std::cout << "错误输入" << std::endl;
                    return;
        }
    }
    if(top != -1)
    std::cout << "error2" << std::endl;
    else
    std::cout << "yes" << std::endl;
}



int main(void)
{
    std::string s1="{[()]}{}";
    test01(s1);
    return 0;
}