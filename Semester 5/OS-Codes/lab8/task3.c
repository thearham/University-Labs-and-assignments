#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

char* fileName;
char* string;
bool isFind;
void* search(void* arg)
{
    if(!isFind)
    {
        char buffer[100];
        FILE *fp;
        fp=fopen(fileName,"r");
        while(fscanf(fp,"%s",buffer)==1)
        {
            printf("%s %s\n",string,buffer);
            if((strcmp(buffer,string)==0))
            {
                isFind=true;
                break;
            }
        }
    }
    pthread_exit(NULL);

}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Usage: %s <filename> <integer> <string>\n", argv[0]);
        return 1;
    }
    fileName = argv[2];
    int number = atoi(argv[1]); 
    string = argv[3];
    printf("Filename: %s\n", fileName);
    printf("Integer: %d\n", number);
    printf("String: %s\n", string);
    pthread_t *arrThreads=(pthread_t*)malloc(number*(sizeof(pthread_t)));

    for(int i=0;i<number;i++)
    {
        pthread_create(&arrThreads[i],NULL,&search,NULL);
        sleep(2);
    }


    for(int i=0;i<number;i++)
    {
        pthread_join(arrThreads[i],NULL);
    }

    if(isFind) printf("Word find in the file.\n");
    else printf("Word is not find in the file.\n");
    return 0;
}