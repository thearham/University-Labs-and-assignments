#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Maximum capacity of the prayer room
#define MAX_CAPACITY 3

// Counters for men and women in the prayer room
int men_count = 0;
int women_count = 0;

// Semaphores for synchronization
sem_t room_mutex;   // For mutual exclusion
sem_t room_capacity; // To ensure no more than MAX_CAPACITY people in the room

void* men(void* arg) {
    int* id = (int*)arg;

    // Wait to ensure no more than MAX_CAPACITY people in the room
    sem_wait(&room_capacity);

    // Enter critical section
    sem_wait(&room_mutex);

    // If there are no women, enter the prayer room
    while (women_count > 0) {
        sem_post(&room_mutex);
        sleep(1); // Wait before trying again
        sem_wait(&room_mutex);
    }

    // Increase men count
    men_count++;

    printf("Man %d entered the prayer room. Men count: %d\n", *id, men_count);

    // Release the mutex
    sem_post(&room_mutex);

    // Simulate time spent in the prayer room
    sleep(2);

    // Enter critical section
    sem_wait(&room_mutex);

    // Decrease men count
    men_count--;

    printf("Man %d left the prayer room. Men count: %d\n", *id, men_count);

    // Release the mutex
    sem_post(&room_mutex);

    // Signal that a spot is available
    sem_post(&room_capacity);

    return NULL;
}

void* women(void* arg) {
    int* id = (int*)arg;

    // Wait to ensure no more than MAX_CAPACITY people in the room
    sem_wait(&room_capacity);

    // Enter critical section
    sem_wait(&room_mutex);

    // If there are no men, enter the prayer room
    while (men_count > 0) {
        sem_post(&room_mutex);
        sleep(1); // Wait before trying again
        sem_wait(&room_mutex);
    }

    // Increase women count
    women_count++;

    printf("Woman %d entered the prayer room. Women count: %d\n", *id, women_count);

    // Release the mutex
    sem_post(&room_mutex);

    // Simulate time spent in the prayer room
    sleep(2);

    // Enter critical section
    sem_wait(&room_mutex);

    // Decrease women count
    women_count--;

    printf("Woman %d left the prayer room. Women count: %d\n", *id, women_count);

    // Release the mutex
    sem_post(&room_mutex);

    // Signal that a spot is available
    sem_post(&room_capacity);

    return NULL;
}
int main() {
    pthread_t men_threads[5];
    pthread_t women_threads[5];

    // Initialize semaphores
    sem_init(&room_mutex, 0, 1);
    sem_init(&room_capacity, 0, MAX_CAPACITY);

    // Create threads for men
    for (int i = 0; i < 5; i++) {
        pthread_create(&men_threads[i], NULL, &men, (void*)&i);
    }

    // Create threads for women
    for (int i = 0; i < 5; i++) {
        pthread_create(&women_threads[i], NULL, &women, (void*)&i);
    }

    // Join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(men_threads[i], NULL);
        pthread_join(women_threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&room_mutex);
    sem_destroy(&room_capacity);

    return 0;
}


