#include "inli.h"

// inline int test::ts(void)
// {
//     return a > b ? a : b;
// }


int main(void)
{
    test a(3,5);
    std::cout << a.ts() <<std::endl;
    return 0;
}


