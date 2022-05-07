#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

 // 下面的代码证明了write 和 fwrite是原子操作
pthread_mutex_t mutex;

#define MAXSIZE 256
int fd;

const char buf[] = "aaaaa";
const char buf2[] = "bbbbb"; 

void *thread(void*arg)
{ 
    printf("this is %d",gettid());
   int get = *(int*)arg;
   int i = 0; 
   if((get)%2==0)
   {
        if((i = write(fd,buf,sizeof(buf))) <0)
        {
            printf("error\n");
        }
        else
        {
            printf("%d a have write\n",i); 
        }
   }
   else
   {
       if((i = write(fd,buf2,sizeof(buf2))) <0)
        {
            printf("error\n");
        }
        else
        {
            printf("%d b have write\n",i); 
        }
   }
   
}

int main()
{
    pthread_t tid[5];
    int p[5] ;
      if((fd = open("file.txt",O_WRONLY)) < 0 )
   {
       perror("open failed\n");
       exit(1);
   }
    for(int i = 0;i < 5;i++)
    {
        p[i] = i;
        pthread_create(&tid[i],NULL,thread,(void*)&p[i]);
    }
    for(int i = 0;i < 5;i++)
    {
        pthread_join(tid[i],NULL);
    }
    close(fd);
    return 0;
}