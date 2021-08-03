#include<iostream>
int main(void){
    int currval = 0;
    int val = 0;
    if(std::cin >> currval){
        int cnt = 1;
        while(std::cin >> val){
            if(val == currval)
                cnt++;
            else{
                std::cout << currval << "occurs" << cnt << " times" << std::endl;
                currval = val;
                cnt = 1;
            }
        }
        std::cout << currval <<" occurs" << cnt << " times" << std::endl;
    }
    return 0;
}