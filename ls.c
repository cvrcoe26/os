#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(){
    char dirname[10];
    DIR *P;
    struct dirent *d;
    printf("Enter the directry name:");
    scanf("%s",dirname);
    P=opendir(dirname);
    if(P==NULL){
        perror("Cannot find directory");
        exit(1);
    }
    while(d=readdir(P)){
        printf("%s\t",d->d_name);
    }

}