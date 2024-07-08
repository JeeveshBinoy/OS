#include <stdio.h>
#include <stdlib.h>

void main(){
    int i,j,n,move,size,RQ[100],tot=0,index,temp,initial;
    
    printf("Enter the number of requests :");
    scanf("%d",&n);
    printf("Enter the request sequence : ");
    for(i=0;i<n;i++)
    scanf("%d",&RQ[i]);
    printf("Enter the initial head position : ");
    scanf("%d",&initial);
    printf("Enter the size of the disk: ");
    scanf("%d",&size);
    printf("Enter the head movement for high 1 or for low 0 : ");
    scanf("%d",&move);
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }   
        }
    }
    
    for(i=0;i<n;i++){
        if(initial<RQ[i]){
            index=i;
            break;
        }
    }
    
    if(move==1){
        for(i=index;i<n;i++){
            tot=tot+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        tot=tot+abs(size-RQ[i-1]-1);
        initial=size-1;
        
        for(i=index-1;i>=0;i--){
            tot=tot+abs(RQ[i]-initial);
            initial=RQ[i];
        } 
    }
    
    else{
        for(i=index-1;i>=0;i--){
            tot=tot+abs(RQ[i]-initial);
            initial=RQ[i];
        } 
        
        tot=tot+abs(RQ[i+1]-0);
        initial=0;
        
        for(i=index;i<n;i++){
            tot=tot+abs(RQ[i]-initial);
            initial=RQ[i];
        }
    }
       
    printf("Total head movements : %d",tot);   
    }
