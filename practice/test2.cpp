#include<iostream>
int do_nothing()
{
    return 0;
}
int max(int a,int b)
{
    do_nothing();
    if(a<b)
    {
        return b;
    }
    else
    {
        return a;
    }
}



int main()
{
    int res = 0;
    int a = 1;
    int b = 2;
    res = max(a,b);
    return res;
}