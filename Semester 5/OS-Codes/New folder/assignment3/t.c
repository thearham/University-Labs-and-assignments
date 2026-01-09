#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 100

void* calculate_partial_factorial(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id == 0 ? 1 : ((thread_id * (*(int*)arg)) + 1);
    int end = (thread_id + 1) * (*(int*)arg);

    unsigned long long partial_product = 1;
    for (int i = start; i <= end; i++) {
        partial_product *= i;
    }
    printf("Thread %d handling range %d to %d partial product: %llu\n", thread_id, start, end, partial_product);
    *(unsigned long long*)arg = partial_product;
    pthread_exit(arg);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <N> <M>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    if (N < M) {
        fprintf(stderr, "Error: N should be greater than or equal to M\n");
        return 1;
    }

    pthread_t threads[M];
    int range = N / M;
    unsigned long long partial_products[M];

    for (int i = 0; i < M; i++) {
        int* thread_arg = malloc(sizeof(int));
        *thread_arg = i;
        if (pthread_create(&threads[i], NULL, calculate_partial_factorial, thread_arg)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    unsigned long long final_product = 1;
    for (int i = 0; i < M; i++) {
        unsigned long long* partial_product;
        if (pthread_join(threads[i], (void**)&partial_product)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }
        final_product *= *partial_product;
        free(partial_product);
    }

    printf("Final product (factorial of %d): %llu\n", N, final_product);
    return 0;
}
