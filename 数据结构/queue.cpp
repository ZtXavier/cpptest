#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int max = MAX;

typedef struct queue
{
    int tag;
    int queue[MAX];
    int front;
    int rear;
}*list_queue,my_queue;

list_queue my_init(void)
{
    list_queue queue = (list_queue)malloc(sizeof(my_queue));
    queue->tag = 0;
    queue->front = queue->rear = 0;
    for(int i = 0;i < MAX;i++)
    queue->queue[i] = -1;
    return queue;
}

bool in_queue(list_queue q,int x)
{
    if(x == -1)
    return false;
    if((q->rear == q->front) && (q->tag == 1))
    {
        std::cout << "该队列已满" << std::endl;
        return false;
    }
    q->tag = 1;
    q->queue[q->rear] = x;
    q->rear = (q->rear+1)%max;
    return true;
}

bool out_queue(list_queue q)
{
    if((q->rear == q->front) && (q->tag == 0))
    {
        std::cout << "该队列为空" << std::endl;
        return false;
    }
    q->tag = 0;
    q->queue[q->front] = -1;
    q->front = (q->front+1)%max;
    return true;
}

void rfront_queue(list_queue q)
{
    if(q->queue[q->front] == -1)
    {
        std::cout << "队头元素为空" << std::endl;
    }
    else
    std::cout << "\t>>队头元素为：" << q->queue[q->front] << std::endl;
}


int main(void)
{
    int num;
    list_queue q = NULL;
    q = my_init();
    while(1)
    {
        std::cout << "是否要出队操作1(y)2(n)" << std::endl;
        std::cin >> num;
        if(num == 1)
        {
            out_queue(q);
        }
        std::cout << "请输入要添加的元素(-1视作不添加)" << std::endl;
        std::cin >> num ;
        if(in_queue(q,num) == true)
        std::cout << "添加元素成功" << std::endl;
        rfront_queue(q);
    }
    return 0;
}