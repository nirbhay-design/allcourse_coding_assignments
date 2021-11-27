#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print(int id) {
    if (id == 0) {
        printf("Hello from the child process with id = %d \n",id);
    } else {
        printf("Hello form the main process with id = %d \n",id);
    }
}

int main(int argc,char * argv[]){
    
    int id = fork();
    printf("after first forking %d \n",id);
    print(id);

    int id1 = fork();
    printf("after second forking %d \n",id1);
    print(id1);

    int id2 = fork();
    printf("after third forking %d \n",id2);
    print(id2);

    return 0;
}