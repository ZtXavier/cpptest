  #include <stdio.h>
 #include <stdlib.h>
 #include <sys/msg.h>
#define MAX_TEXT 512
 struct my_msg_st{
     long int my_msg_type;
         char anytext[MAX_TEXT];
    };
     int main()
     {
        int idx=0;
       int msgid;
         struct my_msg_st data;
         long int msg_to_rcv=0;
         //rcv msg
         msgid=msgget((key_t)1000,0664|IPC_CREAT);//获取消息队列
         if(msgid==-1){
             perror("msgget err");
            exit(-1);
         }   
         while(idx<5){
             //接收消息
             // 和recv 类似,最后一个参数若为0,则是阻塞等待,若是IPC_NOWAIT则在进程
             // 未读到有效消息时直接返回
             if(msgrcv(msgid,(void*)&data,BUFSIZ,msg_to_rcv,0)==-1){
                 perror("msgrcv err");
                exit(-1);
            }
            //打印消息
           printf("msg type:%ld\n",data.my_msg_type);
         printf("msg content is:%s",data.anytext);
           idx++;
        }
        //删除消息队列
        if(msgctl(msgid,IPC_RMID,0)==-1){
           perror("msgctl err");
           exit(-1);
       }
      exit(0);
       }