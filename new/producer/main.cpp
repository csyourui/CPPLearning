// Copyright [2020] <Copyright yourui>
#include <pthread.h>
#include <semaphore.h>

#include <iostream>

#define N 10
int count = 0;
sem_t full;   // 0
sem_t empty;  // N
pthread_mutex_t mutex;
void *Producer(void *) {
  while (true) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
}
void *Comsumer(void *) {}
int main() {
  srand(static_cast<unsigned int>(time(0)));
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, N);
  pthread_mutex_init(&mutex, NULL);
  pthread_t producer, comsumer;
  pthread_create(&producer, NULL, Producer, NULL);
  pthread_create(&comsumer, NULL, Comsumer, NULL);
  pthread_join(producer, NULL);
  pthread_join(comsumer, NULL);
  pthread_mutex_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);
}
