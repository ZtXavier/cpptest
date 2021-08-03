#include<iostream>
int main(void){
    int a = 0,b = 0;
    std::cout << "请输入两个数字" << std::endl;
    std::cin >> a >> b;
    if(a > b){
        while(b != a){
            if((b += 1) == a){    //以后不能这么写，再这么写直接剁手
                break;
            }
            std::cout << b << std::endl;
        }
    }else{
        while(b != a){
            if((a += 1) == b){
                break;
            }
            std::cout << a << std::endl;
        }
    }
    return 0;
}