#include <stdio.h>
#include <stdlib.h>

int full=0;
int empty=5;
int x=0;
int mutex=1;
void producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d",x);
    ++mutex;
}

void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d",x);
    x--;
    ++mutex;
}

void main(){
    int i,n;
    while(1){
    printf("\n1-PRODUCER");
    printf("\n2-CONSUMER");
    printf("\n3-EXIT");
    printf("Enter your choice : ");
    scanf("%d",&n);
    switch(n){
        case 1:
        if((mutex==1) && (empty!=0)){
        producer();
        }
        else{
        printf("Buffer is full");
        }
        break;
        
        case 2:
        if((mutex==1) && (full!=0)){
        consumer();
        }
        else{
        printf("Buffer is empty");
        }
        break;
        
        case 3:
        exit(0);
    }
    }
}
