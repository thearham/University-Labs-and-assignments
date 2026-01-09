#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <pthread.h>
#include <sys/types.h>

void* add(void* ptr)
{
    int* retval = (int*)malloc(sizeof(int));
    int* num = (int*)ptr;
    *retval = num[0] + num[1];
    return (void*)retval;
}

int main()
{
    pthread_t pid1,pid2,pid3;
    void* ret1, *ret2, *ret3;

    int number[] = {10,20,30,50,60,70};

    pthread_create(&pid1,NULL,&add,(void*)&number[0]);
    pthread_create(&pid2,NULL,&add,(void*)&number[2]);
    pthread_create(&pid3,NULL,&add,(void*)&number[4]);

    pthread_join(pid1,&ret1);
    pthread_join(pid2,&ret2);
    pthread_join(pid3,&ret3);

    int retval = *((int*)ret1) + *((int*)ret2) + *((int*)ret3);

    printf("Sum = %d\n", retval);
    
    return 0;
}