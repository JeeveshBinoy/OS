#include <stdio.h>
#include <stdlib.h>

struct sjf{
    int wtime;
    int btime;
    int ttime;
    int pid;
}
p[10];

void main(){
    int i,j,n;
    struct sjf temp;
    float totwtime=0,totttime=0;
    
    printf("Enter the no of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the id : P");
        scanf("%d",&p[i].pid);
        printf("Enter the burst time : ");
        scanf("%d",&p[i].btime);
    }
    
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].btime>p[j].btime){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++){
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }
    
    printf("\nTotal waiting time : %f",totwtime);
    printf("\nAverage waiting time : %f",totwtime/n);
    printf("\nTotal turn around time : %f",totttime);
    printf("\nAverage turn around time : %f",totttime/n);
}
    
    
        
    
    
    
    
    
    
    
    
    
    
    
            
