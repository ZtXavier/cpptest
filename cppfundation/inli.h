#ifndef C4FE8127_B23A_4E5D_96E0_0032BF153B45
#define C4FE8127_B23A_4E5D_96E0_0032BF153B45
#include<iostream>

class test
{
public:
    test(int a,int b){this->a = a;this->b = b;}

    // inline int ts(void){return a > b ? a : b;}  //一般内联函数的声明和函数体在一起可方便让编译器知道内联展开
    inline int ts(void);
private:
    int a;
    int b;
};

int test::ts(void)
{
    return a > b ? a : b;
}

#endif /* C4FE8127_B23A_4E5D_96E0_0032BF153B45 */
