#include <stdio.h>

struct Block{
    int id,size,alloc;
}B[10],temp;

struct Process{
    int id,size,Blockno;
}P[10];

void main(){
    int i,j,b,p;
    printf("Enter the no of blocks : ");
    scanf("%d",&b);
    for(i=0;i<b;i++){
        printf("Enter the id and size of block %d",i+1);
        scanf("%d %d",&B[i].id,&B[i].size);
        B[i].alloc=-1;
    }
    
    printf("Enter the no of process : ");
    scanf("%d",&p);
    for(i=0;i<p;i++){
        printf("Enter the id and size of process %d",i+1);
        scanf("%d %d",&P[i].id,&P[i].size);
        P[i].Blockno=-1;
    }
    
    for(i=0;i<b-1;i++){
        for(j=0;j<b-i-1;j++){
            if(B[j].size>B[j+1].size){
                temp=B[j];
                B[j]=B[j+1];
                B[j+1]=temp;
            }
        }
    }
    
    for(i=0;i<p;i++){
        for(j=0;j<b;j++){
            if(B[j].alloc==-1 && B[j].size>=P[i].size){
                P[i].Blockno=B[j].id;
                B[j].alloc=1;
                break;
            }
        }
    }
    
    printf("Process no\tBlock no\n");
    for(i=0;i<p;i++){
        printf("%d\t\t%d\n",P[i].id,P[i].Blockno);
    }
}
    
    
    
    
    
    
    
    
    
    
    
    
