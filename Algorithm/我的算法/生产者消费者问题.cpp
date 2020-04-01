//
//  生产者消费者问题.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/29.
//  Copyright © 2020 yourui. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10
int count  = 0;
sem_t full;
sem_t empty;//N
pthread_mutex_t mutex;

void* consumer(void *){
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("消费者消费了1个资源，还剩下%d\n", --count);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(3);
    }
}
void* producer(void *){
    while(1){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        printf("生产者生成了1个资源，还剩下%d\n", ++count);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

int main(){
    srand((unsigned int)time(0));

    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);
    
    pthread_t Consumer, Producer;
    pthread_create(&Consumer, NULL, consumer,nullptr);
    pthread_create(&Producer, NULL, producer,nullptr);

    pthread_join(Consumer, NULL);
    pthread_join(Producer, NULL);
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
}

