#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

// Producer function
void* producer(void* arg) {
    int item;

    for(int i = 0; i < 5; i++) {
        item = rand() % 100;

        sem_wait(&empty);              // wait if buffer full
        pthread_mutex_lock(&mutex);    // enter critical section

        buffer[in] = item;
        printf("Produced: %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // exit critical section
        sem_post(&full);               // signal item available

        sleep(1);
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int item;

    for(int i = 0; i < 5; i++) {

        sem_wait(&full);               // wait if buffer empty
        pthread_mutex_lock(&mutex);    // enter critical section

        item = buffer[out];
        printf("Consumed: %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);  // exit critical section
        sem_post(&empty);              // signal space available

        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t p1, p2, c1, c2;

    srand(time(0));   // random seed

    sem_init(&empty, 0, BUFFER_SIZE);  // initially all empty
    sem_init(&full, 0, 0);             // initially no items
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&p2, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer, NULL);
    pthread_create(&c2, NULL, consumer, NULL);

    // Wait for threads
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
