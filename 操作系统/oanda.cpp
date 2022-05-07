#include<iostream>
#include<signal.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/types.h>

sem_t plate;
sem_t orange;
sem_t apple;


void src_init()
{
      sem_init(&plate,0,1);
      sem_init(&apple,0,0);
      sem_init(&orange,0,0);
}

void mother()
{
    sem_wait(&plate);
    sem_post(&orange);
    printf("mother have put an orange\n");
    sem_post(&plate);
}

void father()
{
    sem_wait(&plate);
    sem_post(&apple);
    printf("father have put an apple\n");
    sem_post(&plate);
}

void daugther()
{
    sem_wait(&apple);
    printf("daugther eat an apple\n");
}

void son()
{
    sem_wait(&orange);
    printf("son eat an apple\n");
}

