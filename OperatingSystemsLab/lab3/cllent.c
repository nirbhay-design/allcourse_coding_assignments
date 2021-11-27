#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define Max 1024
// structure for message queue
struct msg_buffer {
    long msg_type;
    char msg_text[Max];
};
  
int main(int argc , char * argv[]){

    struct msg_buffer message;
    strcpy(message.msg_text, "");
    while (!strcmp(message.msg_text , "")) {
        int msgid = msgget(100, 0666 | IPC_CREAT);
        // printf("%d \n",msgid);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        
    }

    printf("Data Received is : %s \n", 
                    message.msg_text);
  
    // msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}