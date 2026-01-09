#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* product(void* args)
{
    int* prod = (int*)malloc(sizeof(int));
    *prod = 1;
    int* arr = (int*)args;

    for (int i = 0; i < 4; i++)
    {
        *prod *= *(arr+i);
        printf("%d\n",*(arr+i));
    }
    printf("partial prod = %d\n",*prod);
    return (void*)prod;
}

int main()
{
    int arr[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
    pthread_t tid[3];
    void* retval;
    long final_product = 1;

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&tid[i],NULL,&product,(void*)(arr+(i*4)));
        pthread_join(tid[i],&retval);
        final_product *= *(int*)retval;
        printf("%d\n",*(int*)retval);
    }
    printf("final prod = %ld\n", final_product);
    return 0;
    
}