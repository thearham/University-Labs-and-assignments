#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NUM_PHILOSOPHERS 5

sem_t chopsticks[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);

        if (id % 2 == 0) {
            // Even-numbered philosopher
            sem_wait(&chopsticks[id]);
            sem_wait(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
        } else {
            // Odd-numbered philosopher
            sem_wait(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
            sem_wait(&chopsticks[id]);
        }

        // Eat
        printf("Philosopher %d is eating.\n", id);

        if (id % 2 == 0) {
            sem_post(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
            sem_post(&chopsticks[id]);
        } else {
            sem_post(&chopsticks[id]);
            sem_post(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
        }

        printf("Philosopher %d is thinking again.\n", id);
    }
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&chopsticks[i], 0, 1);
        ids[i] = i;
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}

