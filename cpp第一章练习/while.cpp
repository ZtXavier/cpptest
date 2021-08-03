#include<iostream>
int main(void){
    int num = 50;
    int val = 0;
    while(num > 0){
        val += num--;
        if(num <= 10)
        std::cout << val << std::endl;
    }
    std::cout << "the number of 0 add to 50 is " << val << std::endl;
    return 0;
}