#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    printf("Hello from the main process \n");

    int id1 = fork();
    printf("process id1 is created \n");
    int id2 = fork();

    printf("process id2 is created \n");

    // if (id != 0) {
    //     wait();
    // }

    if (id1 && id2) {
        printf("Hello I am a parent process with pid : %d \n",getpid());
    } else if (id1 || id2) {
        if (id1) {
            printf("I came from id1 : %d \n",id1);
        } else {
            printf("I came from id2 : %d \n",id2);
        }
    }
    // if (id1 == 0) {
    //     printf("Hello from the child process \n");
    // } else {
    //     printf("hello from the parent process \n");
    // }


    // printf("my process id is : %d \n",id1);


    return 0;
}