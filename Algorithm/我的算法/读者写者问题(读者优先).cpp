//
//  读者写者问题(读者优先).cpp
//  C++Learning
//
//  Created by yourui on 2020/3/29.
//  Copyright © 2020 yourui. All rights reserved.
//
/*
 读者优先意味着只要有一个读者，写者就不能进行写，所以需要一个变量用于统计当前有多少个读者：
 读者进入临界区时会让计算器加一，并且当计算器为1时，读者需要获得数据锁，阻塞其它写进程，知道最后一个读者离开，才释放数据锁。
 
 需要两个信号量，一个保证对计算器的增加是线程安全的。
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t count_mutex, data_mutex;
int count = 0;

void* reader(void*){
    while (1) {
        sem_wait(&count_mutex);
        count++;
        if(count == 1) sem_wait(&data_mutex);
        sem_post(&count_mutex);
        //Read()
        sem_wait(&count_mutex);
        count--;
        if(count == 0) sem_post(&data_mutex);
        sem_post(&count_mutex);
    }
}
void* writer(void*){
    while (1) {
        sem_wait(&data_mutex);
        //Write()
        sem_post(&data_mutex);
    }
}
int main(){
    sem_init(&count_mutex,0,1);
    sem_init(&data_mutex,0,1);
    pthread_t W, R;
    for (int i = 0; i < 3; i++) {
        pthread_create(&W, NULL, writer, nullptr);
        pthread_create(&R, NULL, reader, nullptr);
    }
    pthread_join(R, NULL);
    pthread_join(W, NULL);
    sem_destroy(&count_mutex);
    sem_destroy(&data_mutex);
}
