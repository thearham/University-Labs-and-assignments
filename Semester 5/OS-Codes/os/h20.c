#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t h,o,m;

void* hydrogen(void* args)
{
    sem_post(&h);
    sem_wait(&o);
}

void* oxygen(void* args)
{
    sem_wait(&m);
    sem_wait(&h);
    sem_wait(&h);
    sem_post(&m);
    printf("h20 formed\n");
    sem_post(&o);
    sem_post(&o);

}

int main()
{
    sem_init(&h,0,0);
    sem_init(&o,0,0);
    sem_init(&m,0,1);

    pthread_t tid_o[6];
    pthread_t tid_h[12];

    int j = 0, count = 0;
    for (int i = 0; i < 12; i++)
    {
        //count++;
         if (j < 6)
        {
            pthread_create(&tid_o[j],NULL,&oxygen,NULL);
            j++;
            //count = 0;
        }
        pthread_create(&tid_h[i],NULL,&hydrogen,NULL);
       
    }
    
    j = 0, count = 0;
    for (int i = 0; i < 12; i++)
    {
        //count++;
        if (j < 6 )
        {
            pthread_join(tid_o[j],NULL);
            j++;
            //count = 0;
        }
        
        pthread_join(tid_h[i],NULL);
        
        
    }
    for (int i = 0; i < 3; i++)
    {
        
        
    }
    
    
    sem_destroy(&h);
    sem_destroy(&o);
    sem_destroy(&m);
}