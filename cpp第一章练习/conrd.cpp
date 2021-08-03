#include<iostream>
int main(void){
    int sum = 0;
    int value = 0;
    while(std::cin >> value){
        sum += value;
    }
    std::cout << "sum is: " << sum << std::endl;
    return 0;
}