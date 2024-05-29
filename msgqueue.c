#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

struct msg_buffer { 
    long msg_type; 
    char msg_text[100]; 
} msg; 
  
int main() 
{ 
    int msgqid = msgget(100, 0666 | IPC_CREAT); 
    msg.msg_type = 1;
    printf("Enter message: ");
    fgets(msg.msg_text,sizeof(msg.msg_text),stdin);
    msgsnd(msgqid,&msg,sizeof(msg),0);
    printf("Waiting for a message from client...\n");
    msgrcv(msgqid, &msg, sizeof(msg), 1, 0); 
    printf("Message received from client : %s\n",msg.msg_text); 
    msgctl(msgqid, IPC_RMID, NULL); 
    return 0; 
}