#include<iostream>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<string>

#define MAX_CON 1024

struct my_msg_st {
    long int my_msg_type; // 存放我的消息类型

    char anytext[MAX_CON]; // 存放消息内容
};



// ● 若mtype=0，表示获取队列中的第一个可用消息；
// ● 若mtype>0，表示获取队列中与该值类型相同的第一个消息；
// ● 若mtype<0，表示获取队列中消息类型小于或等于其绝对值的第一个消息


// 连续发送五次消息
int main() {
    int idx = 0;
    int msgid;
    struct my_msg_st data;
    char buf[1024];
    msgid = msgget((key_t) 1000, 0664 | IPC_CREAT);
    if(msgid == -1) {
        perror("msgerr");
        exit(-1);
    }
    while(idx < 5) {
        std::cout << "write it into msg" << std::endl;
        std::cin >> buf;
        // 这里的消息类型需要注意
        data.my_msg_type = rand() %3 + 1 ;
        strcpy(data.anytext,buf);
        if(msgsnd(msgid, (void*)&data,sizeof(data),0) == -1) {
            perror("msgerr");
            exit(-1);
        }
        idx++;
    }
    return 0;
}