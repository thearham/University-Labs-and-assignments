#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* factorial_thread(void* arg) {
    int n = *(int *)arg;
    int* result = (int*)malloc(sizeof(int));
    *result = 1;

    for (int i = 1; i <= n; ++i) {
        *result = i;
    }

    pthread_exit((void *)result);
}

int main(int argc, char* argv[]) {
    int number;
    
    number = atoi(argv[1]);
    
    printf("Entered number to calculate its factorial is: %d\n",number);

    if(number == 0 || number == 1){
    
      printf("Factorial of %d is %d\n", number, 1);
    
    }

    else if (number < 0){
        printf("Factorial is not defined for negative numbers.\n");
        exit(-1);
    } 
    
    else {
        pthread_t thread[number];
        void* result;
        int thread_num[number];
        int fact = 1;
        
        for(int i = 0; i < number; i++){
        
        thread_num[i] = i + 1;
        pthread_create(&thread[i], NULL, factorial_thread, (void *)&thread_num[i]);
        
        }
        
        for(int i = 0; i < number; i++){
        
        pthread_join(thread[i], &result);
        fact = fact * (*(int*)result);
        
        }
        
        printf("Factorial of %d is %d\n", number, fact);
    }

    return 0;
}
