#include <stdio.h>
void main(){
    int i,j,k,n,count=0,m[25],used[10]={0},rs[50],f,pf=0;
    printf("Enter the length : ");
    scanf("%d",&n);
    printf("Reference string : ");
    for(i=0;i<n;i++)
    scanf("%d",&rs[i]);
    printf("Frames : ");
    scanf("%d",&f);
    
    for(i=0;i<f;i++)
    m[i]=-1;
    
    printf("Page Replacement\n");
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i]){
                used[k]=i+1;
                break;
            }
        }
        
        if(k==f){
            int mintime=used[0],minindex=0;
            for(j=1;j<f;j++){
                if(used[j]<mintime){
                    mintime=used[j];
                    minindex=j;
                }
            }
            m[minindex]=rs[i];
            used[minindex]=i+1;
            pf++;
            
            }
            
            for(j=0;j<n;j++)
            printf("%d\t",m[j]);
            
            printf("\n");
    }
    printf("Total page faults: %d",pf);
}
