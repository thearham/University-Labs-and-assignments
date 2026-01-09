#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int divs;

void* factorial(void* arg)
{
    
    int* a= (int*)arg;
    int j = 1;
    for (int i = 0; i < divs; i++)
    {
        j *= *a;
        (*a)--;
    }
    *a = j;  
    
    pthread_exit(a);
}

int main(int argc, char* argv[])
{
    const int threads = atoi(argv[2]);
    int number = atoi(argv[1]);
    if (number < threads)
    {
        perror("N < M\n");
    }
    
    pthread_t* tid = (pthread_t*)malloc(sizeof(pthread_t)*threads);
    void* retval;
    int product = 1;
    divs = number/threads;
    for (int i = 0; i < threads; i++)
    {
        int numberToSend = number - (divs*i);       
        pthread_create(tid+i,NULL,&factorial,(void*)&numberToSend);
        pthread_join(tid[i],&retval);
        printf("%d\n", *(int*)retval);
        
        product *= *(int*)retval;
    }
    
    
    printf("%d\n", product);
    return 0;
}