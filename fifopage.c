#include <stdio.h>
void main(){
    int i,j,k,n,f,rs[50],m[50],count=0,pf=0;
    
    printf("Enter the reference string length : ");
    scanf("%d",&n);
    printf("Enter the reference string : ");
    for(i=0;i<n;i++)
    scanf("%d",&rs[i]);
    printf("Enter the number of frames : ");
    scanf("%d",&f);
    
    for(i=0;i<f;i++)
    m[i]=-1;
    
    printf("Page Replacement\n");
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i])
            break;
        }
        
        if(k==f){
            m[count++]=rs[i];
            pf++;
        }
        
        if(count==f){
            count=0;
        }
        
        for(j=0;j<f;j++)
        printf("%d\t",m[j]);
        
        if(k==f)
        printf("Page Fault no: %d\n",pf);
        
        else
        printf("\n");
    } 
    
    printf("Total Page Faults : %d",pf);
    
}   
