#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define CHAIRS 1 
#define WAITING_ROOM 5 
#define CUSTOMERS 10 
sem_t barber_sem; 
sem_t customer_sem; 
sem_t mutex; 
sem_t waiting_room_sem;

int waiting_customers = 0;
void *barber(void *arg) 
{
    while (1) {
        sem_wait(&customer_sem); 
        sem_wait(&mutex); 
        waiting_customers--;
        printf("Barber is cutting hair...\n");
        sleep(2); 
        sem_post(&mutex);
        printf("Barber is done cutting hair...\n");
        sem_post(&barber_sem); 
    }
}

void *customer(void *arg) 
{
    int id = *(int *)arg;
    sem_wait(&waiting_room_sem);
    sem_wait(&mutex); 
    waiting_customers++; 
    printf("Customer %d is waiting...\n", id);
    sem_post(&mutex); 
    sem_post(&customer_sem);
    sem_wait(&barber_sem); 
    printf("Customer %d is leaving...\n", id);
    sem_post(&waiting_room_sem); 
}
int main() {
    sem_init(&barber_sem, 0, 0); 
    sem_init(&customer_sem, 0, 0);
    sem_init(&mutex, 0, 1); 
    sem_init(&waiting_room_sem, 0, WAITING_ROOM); 

    pthread_t barber_thread;
    pthread_create(&barber_thread, NULL, barber, NULL);

    int customer_ids[CUSTOMERS];
    pthread_t customer_threads[CUSTOMERS];
    for (int i = 0; i < CUSTOMERS; i++) {
        customer_ids[i] = i;
        pthread_create(&customer_threads[i], NULL, customer, &customer_ids[i]);
    }

    for (int i = 0; i < CUSTOMERS; i++) {
        pthread_join(customer_threads[i], NULL);
    }

    pthread_join(barber_thread, NULL);

    sem_destroy(&barber_sem);
    sem_destroy(&customer_sem);
    sem_destroy(&mutex);
    sem_destroy(&waiting_room_sem);

    return 0;
}
