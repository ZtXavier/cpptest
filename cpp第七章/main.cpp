#include<iostream>
#include"header.h"

bool flag = true;
int num = 5;

int factorial(int num)
{
    unsigned long sum = 1;
    for(int i = 1;i <= num;i++)
    {
        sum *= i;
    }
    if(flag)
    {
        return sum;
    }
    else
    {
        return 0;
    }
}
