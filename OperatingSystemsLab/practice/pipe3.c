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
        // close(fd[1]);
        int n;
        if (read(fd[0],&n,sizeof(int)) < 0) {
            printf("not able to read\n");
            return 4;
        }
        close(fd[0]);
        printf("got here at child pid : %d , number %d\n",getpid(),n);
        n = n * 2;
        if (write(fd[1],&n,sizeof(int)) < 0) {
            printf("not able to write\n");
            return 3;
        }
        close(fd[1]);
        printf("wrote from pid: %d , number : %d\n",getpid(),n);
    } else {
        srand(time(NULL));
        int n;
        n = rand() % 100 + 1;
        // close(fd[0]);
        if (write(fd[1],&n,sizeof(int)) < 0 ) {
            printf("not able to write initially\n");
            return 5;
        }
        close(fd[1]);
        printf("Number genereated at pid : %d , number : %d\n",getpid(),n);
        wait(NULL);
        
        close(fd[1]);
        int m;
        if (read(fd[0],&m,sizeof(int)) < 0) {
            printf("not able to read child send signal\n");
            return 6;
        }
        close(fd[0]);
        printf("got from child process pid : %d , number : %d\n",getpid(),m);
        // wait(NULL);
    }
    
    return 0;
}