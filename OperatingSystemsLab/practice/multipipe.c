#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
// write on fd[1] and read from fd[0]
int main(int argc , char * argv[]) {
    int fd[2],df[2];
    if (pipe(fd) == -1) {
        return 2;
    }
    if (pipe(df) == -1) {
        return 3;
    }
    int pid = fork();
    
    
    
    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        close(fd[1]);
        int n;
        read(fd[0],&n,sizeof(int));
        close(fd[0]);
        printf("got here at child pid : %d , number %d\n",getpid(),n);
        n = n * 2;
        close(df[0]);
        write(df[1],&n,sizeof(int));
        close(df[1]);
        printf("wrote from pid: %d , number : %d\n",getpid(),n);
    } else {
        srand(time(NULL));
        int n;
        n = rand() % 100 + 1;
        close(fd[0]);
        write(fd[1],&n,sizeof(int));
        close(fd[1]);
        printf("Number genereated at pid : %d , number : %d\n",getpid(),n);
        wait(NULL);
        
        close(df[1]);
        int m;
        read(df[0],&m,sizeof(int));
        close(df[0]);
        printf("got from child process pid : %d , number : %d\n",getpid(),m);
        // wait(NULL);
    }
    
    return 0;
}