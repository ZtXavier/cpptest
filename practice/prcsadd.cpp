// 微信支付 进程相加

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

#define N 101
#define READ_END 0
#define WRITE_END 1

int main() {
    pid_t pid;
    int fd[2];
    int arr[N];

    for(int i = 0; i < N; i++) {
        arr[i] = i;
    }

    if(pipe(fd) == -1) {
        fprintf(stderr,"pipe failed.\n");
        return 1;
    }

    pid = fork();
    if(pid < 0) {
        fprintf(stderr,"pipe failed.\n");
        return 1;
    }

    if(pid == 0) {
        close(fd[READ_END]);
        int ans = 0;
        for(int i = 0;i < N/2; ++i) {
            ans += arr[i];
        }
        write(fd[WRITE_END],&ans,sizeof(int));
        close(fd[WRITE_END]);
    } else if (pid > 0) {
        close(fd[WRITE_END]);
        int right = 0;
        for(int i = N / 2; i < N; i++) {
            right += arr[i];
        }
        wait(NULL); // 父进程需要等待子进程的结束
        int left = 0;
        read(fd[READ_END],&left,sizeof(int));
        close(fd[READ_END]);
        int sum = left + right;
        printf("SUM is %d\n",sum);
    }
    return 0;
}