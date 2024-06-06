#include <stdio.h>
#include <stdlib.h>

void main(){
    int i,j,n,b[10],p[10],wt[10],tat[10],com[10],temp1,temp2;
    float totwtime=0.0,totttime=0.0;
    printf("Enter the no of process : ");
    scanf("%d",&n);
    printf("Enter burst time : ");
    for(i=0;i<n;i++){
    scanf("%d",&b[i]);
    }
    printf("Enter the priority : ");
    for(i=0;i<n;i++){
    scanf("%d",&p[i]);
    }
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i]>p[j]){
                temp1=b[i];
                b[i]=b[j];
                b[j]=temp1;
                
                temp2=p[i];
                p[i]=p[j];
                p[j]=temp2;
            }
        }
    }
    
    com[0]=b[0];
    wt[0]=0;
    
    for(i=1;i<n;i++){
    com[i]=b[i]+com[i-1];
    }
    
    for(i=0;i<n;i++){
    tat[i]=com[i];
    wt[i]=tat[i]-b[i];
    totttime+=tat[i];
    totwtime+=wt[i];
    }
    
    printf("\nTotal waiting time : %f",totwtime);
    printf("\nAverage waiting time : %f",totwtime/n);
    printf("\nTotal turn around time : %f",totttime);
    printf("\nAverage turn around time : %f",totttime/n);
}
    
