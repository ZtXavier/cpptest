#include<iostream>
#include"screen.h"

int main(void)
{
    Screen myscreen(5,5,'x');
    myscreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myscreen.display(std::cout);
    std::cout << myscreen.size() << std::endl;
    std::cout << std::endl;
    return 0;
}