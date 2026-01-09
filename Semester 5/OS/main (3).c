#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdbool.h>
sem_t company,costumer;
int buffer[30];
int in=0, out=0; 
bool flag=false;
void* Company()
{
    for(int i=0;i<30;i++)
    {
        sem_wait(&company);
        buffer[in]=(i+1)%20;
        printf("Command send by the company is : %d\n",buffer[in]);
        in=(in+1);
        sem_post(&costumer);
    }
}

void* Costumer()
{
    for(int i=0;i<30;i++)
    {
        sem_wait(&costumer);
        for(int i=0;i<out;i++)
        {
            if(buffer[i]==buffer[out])
            {
                flag=true;
                break;
            }
            else flag=false;
        }
        if(flag==false)
        {
            printf("Command read by the costumer is : %d\n",buffer[out]);
        }
        out=(out+1);
        sem_post(&company);
    }
}
int main()
{
    pthread_t pid1,pid2;
    sem_init(&company,0,20);
    sem_init(&costumer,0,0);
    pthread_create(&pid1,NULL,&Company,NULL);
    pthread_create(&pid2,NULL,&Costumer,NULL);
    pthread_join(pid1,NULL);
    pthread_join(pid2,NULL);
    
    return 0;
}
