#include<iostream>  
#include<pthread.h>  
#include<unistd.h>
using namespace std;  
  

  // pthread_once 与其名字一样,在多个线程中定义这个函数最终只会执行一次
  // 这里定义pthread_once的参数
pthread_once_t once = PTHREAD_ONCE_INIT;  
  
void once_run(void)  
{  
        cout<<"once_run in thread "<<(unsigned int )pthread_self()<<endl;  
}  
  
void * child1(void * arg)  
{  
        pthread_t tid =pthread_self();  
        cout<<"thread1 "<<(unsigned int )tid<<" enter"<<endl;  
        pthread_once(&once,once_run);  
        cout<<"thread1 "<<tid<<" return"<<endl;  
}  
  
  
void * child2(void * arg)  
{  
        pthread_t tid =pthread_self();  
        cout<<"thread2 "<<(unsigned int )tid<<" enter"<<endl;  
        pthread_once(&once,once_run);  
        cout<<"thread2 "<<tid<<" return"<<endl;  
}  
  
int main()  {  
        pthread_t tid1,tid2;  
        cout<<"hello"<<endl;  
        pthread_create(&tid1,NULL,child1,NULL);  
        pthread_create(&tid2,NULL,child2,NULL);  
        sleep(10);  
        cout<<"main thread exit"<<endl;  
        return 0;  
}