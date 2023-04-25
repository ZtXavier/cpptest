#include<stdio.h>
#include<malloc.h>
#include<unistd.h>

int main() {
    printf("使用cat /proc/%d/maps 查看内存分配\n",getpid());

    void *addr = malloc(1);
    printf("addr的起始地址:%x\n",addr);
    printf("使用cat /proc/%d/maps 查看内存分配\n",getpid());
    getchar();
    free(addr);
    printf("释放了1字节的内存,但是heap不会释放\n");
    getchar();

    
    return 0;
}
