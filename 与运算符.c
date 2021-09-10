#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main(void)
{
    uint16_t m = 1024;
    uint16_t n = 64;
    uint16_t l = m&(n );            //与运算
    uint16_t o = m&~(n );           //与非运算
    printf("剩余的数据个数%d\n",l);        
    printf("整除的最后一个数据的位置%d\n",o);
    return 0;
}