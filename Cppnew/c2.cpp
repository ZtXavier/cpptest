#include<iostream>

int main()
{
    constexpr auto add1 = [](int n,int m){
        auto func1 = [=]{return n;};
        auto func2 = [=]{return m;};
        return [=] {return func1() + func2();};
    };
    constexpr auto add2 = [](int n,int m){
        return m + n;
    };

    auto add3 = [](int n,int m){
        return n + m;
    };
    int sum1 = add1(30,50)();
    int sum2 = add2(sum1,4);
    constexpr int sum3 = add3(1,2);
    int sum4 = add2(10,2);
    return 0;
}