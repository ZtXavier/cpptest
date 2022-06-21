#include<iostream>
#include"speech.hpp"


int main()
{
    Speech sp;
    for(std::map<int,Speaker>::iterator it = sp.m_speaker.begin();it != sp.m_speaker.end();++it)
    {
            std::cout << "选手编号:"  << it->first << "姓名:" << it->second.s_name << "分数:" << it->second.m_score[0] << std::endl;
    }
    int choice = 0;
    while(true)
    {
        sp.show_Menu();
        std::cout << "请输入你的选择：" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
                case 1: 
                sp.complete_begin();

        break;

                case 2:

        break;

                case 3:

        break;
               
                case 0:
                        sp.exit_Menu();
                        return 0;

                default:
                        std::cout << "请重新选择:" << std::endl;
        break;
        }
    }
    return 0;
}