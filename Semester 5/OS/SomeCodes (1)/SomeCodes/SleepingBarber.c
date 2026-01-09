#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_CUSTOMERS 5
#define NUM_CHAIRS 3

sem_t barber_semaphore;   // Semaphore for barber
sem_t customer_semaphore; // Semaphore for customers
sem_t mutex;              // Semaphore for mutual exclusion

int waiting_customers[NUM_CHAIRS]; // Array to keep track of waiting customers
int count = 0; // Number of waiting customers

void* barber(void* arg) {
    while (1) {
        printf("The barber is sleeping...\n");
        sem_wait(&barber_semaphore);

        sem_wait(&mutex);
        if (count > 0) {
            int customer = waiting_customers[0];
            // Shift the remaining customers forward
            for (int i = 0; i < count - 1; i++) {
                waiting_customers[i] = waiting_customers[i + 1];
            }
            count--;
            printf("The barber is cutting hair for customer %d\n", customer);
            sem_post(&mutex);

            // Simulate haircut time
            sleep(2);
            printf("The barber has finished cutting hair for customer %d\n", customer);
            sem_post(&customer_semaphore);
        } else {
            sem_post(&mutex);
        }
    }
    return NULL;
}

void* customer(void* arg) {
    int index = *(int*)arg;
    sleep(2);

    sem_wait(&mutex);
    if (count < NUM_CHAIRS) {
        waiting_customers[count++] = index;
        printf("Customer %d is waiting in the waiting room\n", index);
        sem_post(&mutex);
        sem_post(&barber_semaphore);
        sem_wait(&customer_semaphore);
        printf("Customer %d has finished getting a haircut\n", index);
    } else {
        printf("Customer %d is leaving because the waiting room is full\n", index);
        sem_post(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t barber_thread;
    pthread_t customer_threads[MAX_CUSTOMERS];

    // Initialize the semaphores
    sem_init(&barber_semaphore, 0, 0);
    sem_init(&customer_semaphore, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create the barber thread
    pthread_create(&barber_thread, NULL, barber, NULL);

    // Create customer threads
    int customer_ids[MAX_CUSTOMERS];
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        customer_ids[i] = i;
        pthread_create(&customer_threads[i], NULL, customer, &customer_ids[i]);
    }

    // Wait for customer threads to finish
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        pthread_join(customer_threads[i], NULL);
    }

    return 0;
}
