#include <stdio.h>
#include <stdlib.h>

struct fcfs{
    int pid;
    int wtime;
    int atime;
    int ttime;
    int btime;
    int ctime;
}p[20];

void main(){
    int i,n;
    float totwtime=0,totttime=0;
    
    printf("process:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter the burst time and arrival time ");
        scanf("%d %d",&p[i].btime,&p[i].atime);
    }
    p[0].ctime=p[0].atime+p[0].btime;
    p[0].wtime=p[0].atime;
    p[0].ttime=p[0].btime;
    totwtime+=p[0].wtime;
    totttime+=p[0].ttime;
    
    for(i=1;i<n;i++){
        if(p[i].atime>p[i-1].ctime){
            p[i].ctime=p[i].atime+p[i].btime;
        }
        else{
            p[i].ctime=p[i-1].ctime+p[i].btime;
        }
        
        p[i].wtime=p[i].ctime-p[i].atime-p[i].wtime;
        p[i].ttime=p[i].ctime-p[i].atime;
        totwtime+=p[i].wtime;
        totttime+=p[i].ttime;
        }
        
        printf("\nTotal waiting time: %f", totwtime);
    printf("\nAverage waiting time: %f", (float)totwtime / n);
    printf("\nTotal turnaround time: %f", totttime);
    printf("\nAverage turnaround time: %f\n", (float)totttime / n);
    
}
