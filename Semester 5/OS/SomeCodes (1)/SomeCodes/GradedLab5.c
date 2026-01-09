#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function prototype
long compare_and_set(long *flag, long expected, long new);

asm( 
"compare_and_set:;"
"movq %rsi,%rax;"       // Move expected into %rax
"lock cmpxchgq %rdx,(%rdi);" // Compare %rax with *flag, if equal, set *flag to new
"retq;"                // Return
);

// Shared data
int shared_data;
long flag = 0;

void* thread1_func(void* arg) {
    for (int i = 1; i <= 10; ++i) {
        while (compare_and_set(&flag, 0, 1) != 0) {
            sleep(1);
        }

        shared_data = i;
        printf("Thread 1: Sent %d\n", i);
        
        flag = 1;
    }
    return NULL;
}

void* thread2_func(void* arg) {
    for (int i = 1; i <= 10; ++i) {
        while (compare_and_set(&flag, 1, 0) != 1) {
            sleep(1);
        }

        printf("Thread 2: Received %d\n", shared_data);
    
        flag = 0;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

