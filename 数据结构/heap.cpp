#include<iostream>
#include"heap.h"


void test01()
{
    int a[] = {5,7,2,9,1,3,2,4};
    int sz = sizeof(a)/sizeof(int);
    max_heap h1(a,sz);
    h1.heap_sort();
    h1.display();
}


int main(void)
{
    test01();
    return 0;
}