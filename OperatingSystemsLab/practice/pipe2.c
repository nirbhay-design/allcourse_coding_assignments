#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
// write on fd[1] and read from fd[0]
int main(int argc , char * argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        return 2;
    }
    
    int pid = fork();

    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        close(fd[0]);
        int n;
        printf("Enter number : ");
        scanf("%d",&n);
        write(fd[1],&n,sizeof(int));
        printf("send from %d pid and the number was %d\n",getpid(),n);
        close(fd[1]);
    } else {
        close(fd[1]);
        int n;
        read(fd[0],&n,sizeof(int));
        printf("received at pid: %d, the number : %d\n",getpid(),n);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}