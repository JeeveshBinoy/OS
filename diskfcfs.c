#include <stdio.h>
#include <stdlib.h>

void main(){
int RQ[100],i,n,initial,totalheadmov=0;
printf("Enter the no of request=");
scanf("%d",&n);
printf("Enter the request=");
for(i=0;i<n;i++)
scanf("%d",&RQ[i]);
printf("Enter the initial =");
scanf("%d",&initial);

for(i=0;i<n;i++)
{
totalheadmov=totalheadmov+abs(RQ[i]-initial);
initial=RQ[i];
}

printf("Head mov = %d",totalheadmov);

}

