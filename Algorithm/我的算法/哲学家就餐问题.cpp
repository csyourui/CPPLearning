//
//  哲学家就餐问题.cpp
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
#define N 5
int philosophers[N] = {0, 1, 2, 3, 4};
//互斥量使用的参数
pthread_mutex_t chops[N];
pthread_mutex_t mutex;
void* philosopher (void* arg) {
    int i = *(int *)arg;
    int left = i;
    int right = (i + 1) % N;
    while (1) {
        printf("哲学家%d正在思考问题\n", i);
        sleep(rand()%5+1);
        pthread_mutex_lock(&mutex);
        printf("哲学家%d饿了\n", i);
        pthread_mutex_lock(&chops[left]);
        printf("哲学家%d拿起了%d号筷子, 现在有一支筷子\n", i, left);
        pthread_mutex_lock(&chops[right]);
        printf("哲学家%d拿起了%d号筷子, 现在有两支筷子\n", i, right);
        sleep(rand()%5+1);
        pthread_mutex_unlock(&chops[left]);
        printf("哲学家%d放下了%d号筷子\n", i, left);
        pthread_mutex_unlock(&chops[right]);
        printf("哲学家%d放下了%d号筷子\n", i, right);
        pthread_mutex_unlock(&mutex);
        return nullptr;
    }
}
int main (int argc, char **argv) {
    srand((unsigned int) time(NULL));
    pthread_t PHD[N];

    for (int i=0; i<N; i++) {
        pthread_mutex_init(&chops[i], NULL);
    }
    pthread_mutex_init(&mutex, NULL);
    for (int i=0; i<N; i++) {
        pthread_create(&PHD[i], NULL, philosopher,(void*)&philosophers[i]);
    }
    for (int i=0; i<N; i++) {
        pthread_join(PHD[i], NULL);
    }

    for (int i=0; i<N; i++) {
        pthread_mutex_destroy(&chops[i]);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}

