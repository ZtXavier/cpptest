#include<iostream>
int main(void){
    int a = 0,b = 0;
    std::cout << "请输入两个数" << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cout << "The result " << a << " and " << b << " is " << a*b << std::endl;
    return 0;
}