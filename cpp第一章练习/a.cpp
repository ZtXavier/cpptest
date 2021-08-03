#include<iostream>
int main(void){
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0,v2 = 0;
    std::cin >> v1 >> v2;   //在终端输入v1,v2的值
    std:: cout << "The sum of" << v1 << "and" << v2 << "is" <<  v1 + v2 << std::endl;
    //输出流,在终端打印
    return 0;
}