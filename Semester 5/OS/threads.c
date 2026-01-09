/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* sum (void* ptr)
{
    int *s = (int*)malloc(sizeof(int));
    int *p = (int*)ptr;
    for(int i=0;i<5;i++)
        *s += p[i];
    
    
    return (void*)s;
}


int main()
{
    void* p1,*p2;
    int array[]= {0,1,2,3,4,5,6,7,8,9};
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,&sum,(void*)&array[0]);
     pthread_create(&tid2,NULL,&sum,(void*)&array[5]);
    
    pthread_join(tid1,&p1);
    pthread_join(tid2,&p2);
    
    int final_sum = *(int*)p1 + *(int*)p2; 
    
    printf("Sum is %d\n",final_sum);
    
    
    return 0;
}
