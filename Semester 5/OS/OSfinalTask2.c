#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void *lowerCase(void *ptr) {
    char *str = (char *)ptr;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert uppercase to lowercase
        }
        i++;
    }
    pthread_exit(NULL);
}
void *upperCase(void *ptr) {
    char *str = (char *)ptr;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Convert uppercase to lowercase
        }
        i++;
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *buffer = argv[1];
    char *arr = (char *)malloc(strlen(buffer) + 1);
    if (arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    
    strcpy(arr, buffer);

    pthread_t tid1,tid2;

    printf("Original string: %s\n", buffer);
    pthread_create(&tid2, NULL, &upperCase,(void*)&arr[0]);
    pthread_join(tid2, NULL);
    printf("Thread 1 working : %s\n", arr);
    sleep(1);
    pthread_create(&tid1, NULL, &lowerCase,(void*)&arr[0]);
    pthread_join(tid1, NULL);
    printf("Thread 2 working : %s\n", arr);
    free(arr);

    return 0;
}
