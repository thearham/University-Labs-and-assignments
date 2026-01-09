/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd1[2],fd2[2];
    pipe(fd1); pipe(fd2);
    
    if(fork()==0) //ls
    {
        close(fd1[0]);
        close(fd2[0]); close(fd2[1]);
        
        dup2(fd1[1],1);
        execlp("ls","ls",NULL);
        return 0;
    }
    
    pid_t pid= fork();
    if(pid==0)//sort
    {
        close(fd1[1]);
        close(fd2[0]);
        
        dup2(fd1[0],0);
        dup2(fd2[1],1);
        
        execlp("sort","sort",NULL);
        return 0;
    }
    
    pid_t pid2 = fork();
    if(fork()==0)
    {
        close(fd1[0]); close(fd1[1]);
        close(fd2[1]);
        dup2(fd2[0],0);
        execlp("more","more",NULL);
        return 0;
        
        
    }
    
    
    
    
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    
    
    waitpid(pid2,NULL,0);
    
    return 0;
}
