#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int size = 0;

int Size(int N, int M) {
    return (N % M == 0) ? (N / M) : ((N / M) + 1);
}

int fact(int num, int range) {
    int result = 1;
    while (num > range && num > 0) {
        result *= num;
        num--;
    }
    return result;
}

void* findFactorial(void* x) {
    int start = *(int*)x;
    int* result = (int*)malloc(sizeof(int));

    *result = fact(start, start - size);
    
    if (start - size < 0) {
        printf("Product of %d and 1 is: %d\n", start, *result);
    } else {
        printf("Product of %d and %d is: %d\n", start, (start - size) + 1, *result);
    }

    return (void*)result;
}

int main(int argc, char** argv) {
    
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    if (M > N) {
        printf("M should be less than or equal to N.\n");
        return 1;
    }

    size = Size(N, M);
    pthread_t threads[M];
    int startPoints[M];
    void* results[M];
    int product = 1;

    for (int i = 0; i < M; i++) {
        startPoints[i] = N - (i * size);
        pthread_create(&threads[i], NULL, findFactorial, &startPoints[i]);
        sleep(2);
        pthread_join(threads[i], &results[i]);
        product *= *((int*)results[i]);
    }

    printf("Factorial of %d = %d\n", N, product);

    return 0;
}
