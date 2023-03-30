#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>


void deal_withc(int n) {
    printf("signal num is %d\n",n);
    // 这里的wait是为了等待子进程结束并回收资源,防止生成僵尸进程
    wait(NULL);
}

int main() {
    // 注册信号函数
    // signal(SIGCHLD, deal_withc);

    pid_t pid = fork();

    int i = 0;
    // 在子进程中
    if(pid == 0) {
        printf("child process is running\n");
        sleep(2);
    } else {
        printf("parent is running\n");
        sleep(10);
        printf("parent 10 over\n");
        sleep(5);
    }
     
    exit(0);
    return 0;
}