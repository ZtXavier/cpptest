#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define M 16             /*缓冲数目*/

#define P(x)     sem_wait(&x)
#define V(x)    sem_post(&x)

int in = 0;         /*生产者放置产品的位置*/
int out = 0;             /*消费者取产品的位置*/

int buff[M] = {0};     /*缓冲初始化为0， 开始时没有产品*/

sem_t empty_sem;         /*同步信号量，当满了时阻止生产者放产品*/
sem_t full_sem;         /*同步信号量，当没产品时阻止消费者消费*/
pthread_mutex_t mutex; /*互斥信号量， 一次只有一个线程访问缓冲*/
sem_t pr_sem;
sem_t co_sem;

/*
 *output the buffer
 */
void print()
{
    int i;
    for(i = 0; i < M; i++)
        printf("%d ", buff[i]);
    printf("\n");
}

/*
 *producer
 */
void *producer(void*)
{
    for(;;)
    {

    
        sleep(1);
        P(empty_sem);
        sem_wait(&pr_sem);
        pthread_mutex_lock(&mutex);

        in = in % M;
        printf("%d(+)produce a product. buffer:",gettid());

        buff[in] = 1;
        print();
        ++in;

        pthread_mutex_unlock(&mutex);
        V(full_sem);
        sem_post(&pr_sem);
    }
   
}

/*
 *consumer
 */
void *consumer(void*)
{
    for(;;)
    {
        sleep(2);
        P(full_sem);
        sem_wait(&co_sem);
        pthread_mutex_lock(&mutex);

        out = out % M;
        printf("%d(-)consume a product. buffer:",gettid());

        buff[out] = 0;
        print();
        ++out;

        pthread_mutex_unlock(&mutex);
        V(empty_sem);
        sem_post(&co_sem);
    }
    
}

void sem_mutex_init()
{
    /*
     *semaphore initialize
     */
    int init1 = sem_init(&empty_sem, 0, M);
    int init2 = sem_init(&full_sem, 0, 0);
    int num1 = sem_init(&pr_sem,0,1);
    int num2 = sem_init(&co_sem,0,1);
    if((num1 !=0) && (num2 != 0))
    {
        printf("error in ctl pthread\n");
        exit(1);
    }
    if( (init1 != 0) && (init2 != 0))
    {
        printf("sem init failed \n");
        exit(1);
    }
    /*
     *mutex initialize
     */
    int init3 = pthread_mutex_init(&mutex, NULL);
    if(init3 != 0)
    {
        printf("mutex init failed \n");
        exit(1);
    }
    
}
int main()
{
    pthread_t id1[4];
    pthread_t id2[4];
    int i;
    int ret;

    sem_mutex_init();
    
    /*create the producer thread*/
    for(int i = 0;i < 4;i++)
    {
        if((ret = pthread_create(&id1[i], NULL, producer, NULL)) != 0)
        {
            printf("producer creation failed \n");
            exit(1);
        }
    }
    
    /*create the consumer thread*/
    for(int i = 0;i < 4;i++)
    {
        
        if((ret = pthread_create(&id2[i], NULL, consumer, NULL)) != 0)
        {
            printf("consumer creation failed \n");
            exit(1);
        }
    }
    for(int i = 0;i < 4;i++)
    {
        pthread_join(id1[i],NULL);
        pthread_join(id2[i],NULL);
    }
    exit(0);
}