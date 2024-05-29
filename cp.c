#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    char buff[30];
    int inp =open("/home/cvr/test",D_RDONLY);
    int op = open("/home/cvr/new",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRT|S_IROTH);
    while(read(inp,&buff,1)) 
        write(op,&buff,1);
    printf("File copied successfully!!");
    close(inp);
    close(op);
    return 0;
}