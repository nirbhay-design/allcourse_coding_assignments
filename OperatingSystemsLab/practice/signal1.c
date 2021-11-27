#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc , char * argv[]) {
    int pid = fork();

    if (pid == 0) {
        while (1) {
            printf("some text goes here\n");
            usleep(50000);
        }
    } else {
        kill(pid,SIGSTOP);
        int t;
        do {
            printf("time in seconds for execturion : ");
            scanf("%d",&t);
            if (t > 0) {
                kill(pid,SIGCONT);
                sleep(t);
                kill(pid,SIGSTOP);
            } else {
                kill(pid,SIGKILL);
            }
        } while (t > 0);
        kill(pid,SIGKILL);
        wait(NULL);
     }
    
    return 0;
}
