#include<iostream>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>


void sys_err(char *str) {
    perror(str);
    exit(1);
}


void sig_handler(int sig) {
    int status;
    pid_t pid;

    while((pid = waitpid(0, &status, WNOHANG)) > 0) {
        if(WIFEXITED(status)) {
            printf("---------child %d exit with %d\n", pid, WEXITSTATUS(status));
        } else if(WIFSIGNALED(status)) {
            printf("child %d killed by the %dth signal\n", pid, WTERMSIG(status));
        }
    }
}


int main() {
    pid_t pid;
    int i;
    sigset_t nmask, omask;
    // 将阻塞sigchld信号
    sigemptyset(&nmask);
    sigaddset(&nmask, SIGCHLD);
    sigprocmask(SIG_UNBLOCK, &nmask, &omask);

    for(int i = 0; i < 10; ++i) {
        pid = fork();
        if(pid == 0) break; // 因为子进程是共享局部变量的
        else if(pid < 0) {
            sys_err("fork");
        }
    }

    if(pid == 0) {
        int n = 1;
        while(n--) {
            printf("child ID %d\n",getpid());
            sleep(5);
        }
        return i + 1;
    } else if(pid > 0) {
        // SIGCHLD 阻塞
        struct sigaction act;
        act.sa_handler = sig_handler;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        sigaction(SIGCHLD, &act, NULL);
        while(1) {
            printf("parent ID %d\n",getpid());
            sleep(1);
        }
    }

    return 0;
}