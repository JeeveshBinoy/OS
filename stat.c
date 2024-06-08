#include <stdio.h>
#include <sys/stat.h>

void main(){
    struct stat sfile;
    stat("stat1.txt",&sfile);
    printf("st_mode=%o",sfile.st_mode);
    printf("\nFile st_uid=%d\n",sfile.st_uid);
    printf("\nFile st_size %ld\n",sfile.st_size);
}
