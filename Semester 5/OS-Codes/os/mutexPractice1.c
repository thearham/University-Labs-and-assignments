#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int count = 0;
void* hello(void* arg)
{
    pthread_mutex_lock(&mutex);
    printf("hello %d\n", *(int*)arg);
    for (int i = 0; i < 100000; i++)
    {
        count++;
    }
    printf("count = %d\n",count);
    pthread_mutex_unlock(&mutex);
        
    return NULL;
}
// void* world(void* arg)
// {
//     pthread_mutex_lock(&mutex);
//     printf("world\n");
//     pthread_mutex_unlock(&mutex);
//     return NULL;
// }

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t tid1, tid2;
    int id[2] = {1,2};
    pthread_create(&tid1, NULL, &hello, (void*)&*(id));
    pthread_create(&tid2, NULL, &hello, (void*)&*(id+1));

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}