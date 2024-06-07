#include <stdio.h>

void main(){
    int i,j,k,y,np,nr,alloc[20][20],max[20][20],avail[50],ind=0;
    printf("Enter the number of process : ");
    scanf("%d",&np);
    printf("Enter the number of resources : ");
    scanf("%d",&nr);
    
    printf("Enter the allocation matrix\n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("Enter the max matrix\n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
        }
    }
    
    printf("Enter the available matrix\n");
    for(i=0;i<nr;i++){
        scanf("%d",&avail[i]);
    }
    
    int finish[np],safe[np],work[nr],need[np][nr];
    
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    
    printf("NEED Matrix");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<nr;i++){
        work[i]=avail[i];
    }
    
    for(i=0;i<np;i++){
        finish[i]=0;
    }
    
    for(k=0;k<np;k++){
        for(i=0;i<np;i++){
            if(finish[i]==0){
                int flag=0;
                for(j=0;j<nr;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safe[ind++]=i;
                    for(y=0;y<nr;y++){
                        work[y]+=alloc[i][y];
                        finish[i]=1;
                    }
                }
            }
        }
    }
    
    printf("\nSafe sequence\n");
    for(i=0;i<=np-1;i++)
    printf("P%d",safe[i]);
    
}

