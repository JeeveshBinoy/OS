#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent *dptr;
void main(){
    char buffer[256];
    DIR *dirp;
    printf("Enter the name of directory : ");
    scanf("%s",buffer);
    if((dirp=opendir(buffer))==NULL){
        printf("Error");
        exit(1);
    }
    while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}


