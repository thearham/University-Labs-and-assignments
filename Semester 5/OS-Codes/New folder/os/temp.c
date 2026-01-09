#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int size=0;

int calculateSize(int N,int M)
{
    if(N%M==0) return N/M;
    else return ((N/M)+1);
}

int fact(int num,int range)
{
    
    int result=1;
    while(num>range&&num>0)
    {
        result=result*num;
        num--;
    }
    return result;
}

void *findFactorial(void *x) {
    int *f = (int*)malloc(sizeof(int));
    *f = *((int*)x);
   
    *f=fact(*f,*f-size);
    
    if(*((int*)x)-size<0)
    {
        printf("Product of %d and ",*((int*)x));
        printf("1 is : %d\n",*f);
    }
    else
    {
        printf("Product of %d and ",*((int*)x));
        printf("%d is : %d\n",(*((int*)x)-size)+1,*f);
    }
    
    return (void*)f;
}


int main(int count,char** argv)
{
    
    int N=atoi(argv[1]);
    int M=atoi(argv[2]);
    int temp;
    void* num[M];
    int product = 1;
    if(M<=N)
    {
        size = calculateSize(N,M);
        pthread_t *arrThread = (pthread_t*) malloc (sizeof(pthread_t)*M);
        for(int i=0;i<M;i++)
        {
            temp=N-(i*size);
            pthread_create(&arrThread[i],NULL,&findFactorial,(void*)&temp);
            pthread_join(arrThread[i],&num[i]);
            sleep(2);

        }
        for (int i = 0; i < M; i++)
        {
            product *= *((int*)num[i]);
        }
        printf("Product (Factorial of %d) = %d\n",N,product);
    }
    else
    {
        printf("Wrong input.");
        
    }
    
    
    return 0;
}

