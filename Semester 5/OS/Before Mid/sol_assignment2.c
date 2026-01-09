/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int n, char* argv[])
{

int fd[2];
pipe(fd);

if(fork()==0)
{
    
    close(fd[1]);
    dup2(fd[0],0);
    close(fd[0]);
    execlp("sort","sort","-n",NULL);
    
    return 0;
    
}

close(fd[0]);
char* ptr = (char*) malloc(20);
for(int i=1;i<n;i++)
{
    sprintf(ptr,"%s\n",argv[i]);
    write(fd[1],(void*)ptr,20);
    
}

close(fd[1]);
wait(NULL);


    return 0;
}
