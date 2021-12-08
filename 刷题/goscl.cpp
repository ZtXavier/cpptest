#include<iostream>
#include<string>
#include<stdio.h>




int main()
{
    int s,v;
    std::cin >> s >> v;
    int minus;
    if (s % v){
        minus = (s / v) + 1;
    }
    int h = 7;
    minus = 60 - minus - 10;
    while(minus < 0){
        if(h <= 0){
            h += 24; 
        }
        h--;
        minus += 60;
    }
    printf("%02d:%02d",h,minus);
    return 0;
}