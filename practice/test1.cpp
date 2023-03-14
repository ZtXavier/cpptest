#include<iostream>
#define min(a,b)((a) <= (b) ? (a) : (b))

int main()
{
    // int *p = 0;      //一个指针指向不确定的地址结果也会不确定
    //char a[] = "asfg";
    //char c = a[10];
    // std::cout << *p << std::endl;
    // int a1 = 0;
    // int a2 = 5;
    // std::cout << min(a1,a2) << std::endl;
    int a[5] = {1,2,3,4,5};
    int *ptr = (int*)(&a+1);
    printf("%d,%d",*(a+1),*(ptr-1));
    return 0;
}