#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include<unistd.h>
#include <stdio.h>

#define MaxItems 5 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pno);
void *consumer(void *cno);

void *producer(void *pno)
{
    int item;
    while(1) {
        item = rand(); // Produce an random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        // Critical Section Begins

        buffer[in] = item;
        printf("Producer : Insert Item %d at %d\n", buffer[in],in);
        in = (in+1)%BufferSize;
        /*
        * This sleep is optional
        * It is added just to observe the output properly
        * becaue without the prog runs very quickly
        */
        sleep(1);

        // Critical section ends here
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *cno)
{
    while(1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        // Critical section begins

        int item = buffer[out];
        printf("Consumer : Remove Item %d from %d\n", item, out);
        out = (out+1)%BufferSize;
        /*
        * This sleep is optional
        * It is added just to observe the output properly
        * becaue without the prog runs very quickly
        */
        sleep(1);

        // Critical section ends here
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{

    pthread_t pro,con;
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize);
    sem_init(&full,0,0);

    pthread_create(&pro, NULL, (void *)producer, NULL);
    pthread_create(&con, NULL, (void *)consumer, NULL);
    pthread_join(pro, NULL);
    pthread_join(con, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;

}
