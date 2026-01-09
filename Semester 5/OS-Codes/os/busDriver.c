#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t boarders,drivers,m;

void* board_passengers(void* args)
{
    sem_post(&boarders);
    sem_wait(&drivers);
}

void* arrive_driver(void* args)
{
    sem_wait(&m);
    
    for (int i = 0; i < 50; i++)
    {
        sem_wait(&boarders);
    }
    
    sem_post(&m);
    printf("Bus Departed\n");

    for (int i = 0; i < 50; i++)
    {
        sem_post(&drivers);
    }
        

}

int main()
{
    sem_init(&boarders,0,0);
    sem_init(&drivers,0,0);
    sem_init(&m,0,1);

    pthread_t tid_drivers[3];
    pthread_t tid_board[150];

    int j = 0, count = 0;
    for (int i = 0; i < 150; i++)
    {
        //count++;
        if (j < 3)
        {
            pthread_create(&tid_drivers[j],NULL,&arrive_driver,NULL);
            j++;
            //count = 0;
        }
        pthread_create(&tid_board[i],NULL,&board_passengers,NULL);
       
    }
    
    j = 0, count = 0;
    for (int i = 0; i < 150; i++)
    {
        //count++;
        if (j < 3 )
        {
            pthread_join(tid_drivers[j],NULL);
            j++;
            //count = 0;
        }
        
        pthread_join(tid_board[i],NULL);
        
        
    }
    
    
    sem_destroy(&boarders);
    sem_destroy(&drivers);
    sem_destroy(&m);
}