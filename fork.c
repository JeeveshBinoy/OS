#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    int pid;
    pid=fork();
    if(pid==0){
        printf("Child process\n");
        printf("Process id : %d\n",getpid());
        
        execlp("/bin/date","date",NULL);
        exit(0);
    }
    
    else if(pid>0){
        printf("Parent process\n");
        printf("Process id : %d\n",getpid());
        wait(NULL);
    }
    
    else{
        printf("Fork failed\n");
        exit(0);
    }
    
}
        
