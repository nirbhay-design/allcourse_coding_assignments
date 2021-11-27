#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc , char * argv[]) {
    int pid = fork();

    if (pid == -1) {
        return 1;
    }

    if (pid == 0) {
        while (1) {
            printf("some text is there\n");
            usleep(50000);

        }
    } else {
        sleep(1);
        kill(pid,SIGSTOP);
        sleep(3);
        kill(pid,SIGCONT);
        wait(NULL);
    }
    return 0;
}