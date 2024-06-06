#include <stdio.h>
#include <stdlib.h>


struct fcfs{
    int pid;
    int btime;
    int ttime;
    int wtime;
    }
    p[10];

void main(){
    int i,n;
    int totwtime=0,totttime=0;
    
    printf("Enter the no of process : ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("\nBurst time of process : ");
        scanf("%d",&p[i].btime);
    }
    
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    
    for(i=0;i<n;i++){
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }
    
    printf("\nTotal waiting time : %d",totwtime);
    printf("\nAverage waiting time : %d",totwtime/n);
    printf("\nTotal turn around time : %d",totttime);
    printf("\nAverage turn around time : %d",totttime/n);
}
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
