//
//  读者写者问题(写者优先).cpp
//  C++Learning
//
//  Created by yourui on 2020/4/1.
//  Copyright © 2020 yourui. All rights reserved.
//

/*
 引入读者计数器，写者计数器信号量
 引入排队信号量，如果有至少一个写者则阻塞排队信号量，而读者只有获得排队信号量才能读，以保证写者优先
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t reader_count_mutex, writer_count_mutex;
sem_t data_mutex, queue_mutex;
int reader_count = 0, writer_count = 0;

void* reader(void*){
    while (1) {
        sem_wait(&queue_mutex);                         //申请队列信号量
        sem_wait(&reader_count_mutex);                  //申请读者计数器信号量
        reader_count++;                                 //读者计数器加1
        if(reader_count == 1) sem_wait(&data_mutex);    //第一个读者，申请数据信号量
        sem_post(&reader_count_mutex);                  //释放读者计数器信号量
        sem_post(&queue_mutex);                         //释放队列信号量
        //Read()
        sem_wait(&reader_count_mutex);                  //申请读者计数器信号量
        reader_count--;                                 //读者计数器减1
        if(reader_count == 0) sem_post(&data_mutex);    //最后一个读者，释放数据信号量
        sem_post(&reader_count_mutex);                  //释放队列信号量
    }
}
void* writer(void*){
    while (1) {
        sem_wait(&writer_count_mutex);
        writer_count++;
        if(writer_count == 1) sem_wait(&queue_mutex);
        sem_post(&writer_count_mutex);
        
        sem_wait(&data_mutex);
        //Write()
        sem_post(&data_mutex);

        sem_wait(&writer_count_mutex);
        writer_count--;
        if(writer_count == 0) sem_post(&queue_mutex);
        sem_wait(&writer_count_mutex);
    }
}
int main(){
    sem_init(&reader_count_mutex, 0, 1);
    sem_init(&writer_count_mutex, 0, 1);
    sem_init(&data_mutex,0,1);
    sem_init(&queue_mutex,0,1);

    pthread_t W, R;
    
    pthread_create(&W, NULL, writer, nullptr);
    pthread_create(&R, NULL, reader, nullptr);
    
    pthread_join(R, NULL);
    pthread_join(W, NULL);
    sem_destroy(&reader_count_mutex);
    sem_destroy(&writer_count_mutex);
    sem_destroy(&data_mutex);
    sem_destroy(&queue_mutex);

}
