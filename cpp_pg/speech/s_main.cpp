#include<iostream>
#include"speech.hpp"


int main()
{
    Speech sp;
    int choice;
    while(true)
    {
        sp.show_Menu();
        std::cout << "请输入你的选择：" << std::endl;
        std::cin >> choice;

        switch(choice)
        {
            case 1: 

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