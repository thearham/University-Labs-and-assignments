#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 50

pthread_mutex_t lock;
sem_t bus_ready;  
sem_t riders_done; 
int waiting_riders = 0;
int boarding_riders = 0;

void *rider(void *arg) {
    pthread_mutex_lock(&lock);
    waiting_riders++;
    pthread_mutex_unlock(&lock);

    
    sem_wait(&bus_ready);

    pthread_mutex_lock(&lock);
    boarding_riders++;
    printf("Rider %d boarded the bus\n", (int)(long)arg);

   
    if (boarding_riders == MAX_CAPACITY || boarding_riders == waiting_riders) {
        sem_post(&riders_done);
    } else {
        // Otherwise, allow the next rider to board
        sem_post(&bus_ready);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void *bus(void *arg) {
    while (waiting_riders > 0) {
        pthread_mutex_lock(&lock);

        if (waiting_riders > 0) {
            boarding_riders = 0;
            sem_post(&bus_ready);
            
            pthread_mutex_unlock(&lock);
            sem_wait(&riders_done);
            pthread_mutex_lock(&lock);
            printf("Bus is departing with %d riders\n", boarding_riders);
            waiting_riders -= boarding_riders;
        } else {
            printf("Bus is departing empty\n");
        }

        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t bus_thread;
    pthread_t rider_threads[100]; 
    pthread_mutex_init(&lock,NULL);
    sem_init(&bus_ready, 0, 0);
    sem_init(&riders_done, 0, 0);

    

    
    for (int i = 0; i < 100; i++) {
        pthread_create(&rider_threads[i], NULL, rider, (void *)(long)i);
    }
    pthread_create(&bus_thread, NULL, bus, NULL);

    
    for (int i = 0; i < 100; i++) {
        pthread_join(rider_threads[i], NULL);
    }

    pthread_join(bus_thread, NULL);

    sem_destroy(&bus_ready);
    sem_destroy(&riders_done);
    pthread_mutex_destroy(&lock);

    return 0;
}
