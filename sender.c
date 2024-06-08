#include <stdio.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

void main(){
    void *shared_memory;
    char buffer[100];
    int shmid;
    shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
    printf("Key of shared memory : %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Process attached at %p\n",shared_memory);
    printf("Enter some data to write to shared memory : \n");
    read(0,buffer,100);
    strcpy(shared_memory,buffer);
    printf("You wrote is : %s\n",(char *)shared_memory);
}
