#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>

void* Arctan(void* arg)
{
    
    long long* n = (long long*)arg;
    double* retval = (double*)malloc(sizeof(double));
    *retval = 0;

    for (int i = 0; i <= *n; i++)
    {
        *retval += pow(-1, i) * ((pow(1,(2*i) + 1)) / ((2*i) + 1) );
        printf("%d\n", i);
    }
    return (void*)retval;  
}

int main()
{
    pthread_t thread;
    void* ret;
    long long n = 100000;
    pthread_create(&thread,NULL,&Arctan, (void*)&n);
    pthread_join(thread, &ret);
    double retval = *((double*)ret);
    printf("Arctan(1) = %lf\n", retval);

    return 0;
    // for (int i = 0; i < 5; i++)
    // {
    //     pthread_create(&threads[i],NULL,&Arctan, (void*)n);
    // }
    
}