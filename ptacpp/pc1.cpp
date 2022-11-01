#include<string>
#include<iostream>



int main() {
    std::string st1 = "111";
    std::string st2 = "l" + st1;
    std::string st3 = "l" + st1;
    if(st2 == st3){
        std::cout << "ok" << std::endl;
    }
    return 0;
}