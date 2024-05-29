#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("usage: perms file_name \nExample: 777 hi.txt");
        return -1;
    }
    const char *perms = argv[1];
    const char *filename = argv[2];
    mode_t mode = strtol(perms,NULL,8);
    if(chmod(filename,mode)==-1) {
        perror("chmod error");
        exit(EXIT_FAILURE);
    }
    printf("permissions changed successfully");
return 0;
}