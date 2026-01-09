#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

pthread_mutex_t mutex,mutex1,mutex2;
sem_t semaphore;
//char* messages[3] = {"uni","of","cp"};
int i = 0;
void* hello(void* arg)
{
    pthread_mutex_lock(&mutex);
    printf("Thread %d says: university\n", *(int*)arg);
    //i++;
    pthread_mutex_unlock(&mutex1);

    return NULL;
}
void* hello1(void* arg)
{
    pthread_mutex_lock(&mutex1);
    printf("Thread %d says: of\n", *(int*)arg);
    //i++;
    pthread_mutex_unlock(&mutex2);

    return NULL;
}
void* hello2(void* arg)
{
    pthread_mutex_lock(&mutex2);
    printf("Thread %d says: central punjab\n", *(int*)arg);
    //i++;
    pthread_mutex_unlock(&mutex);

    return NULL;
}
int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_t tid1, tid2,tid3;
    int id[3] = {1,2,3};
    pthread_create(&tid1, NULL, &hello, (void*)&*(id));
    pthread_create(&tid2, NULL, &hello1, (void*)&*(id+1));
    pthread_create(&tid3, NULL, &hello2, (void*)&*(id+2));

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}