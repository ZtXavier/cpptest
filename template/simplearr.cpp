#include<iostream>
#include"simplearr.hpp"

void test()
{
    Arrary<int> arr(5);
    Arrary<int> arr1(arr);
    arr1 = arr;
}



int main(void)
{
    test();
    return 0;
}
