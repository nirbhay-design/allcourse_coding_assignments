#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigtstp(int sig) {
    printf("stopped not allowed \n");

}

int main(int argc , char * argv[]) {
    struct sigaction sa;
    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP,&sa,NULL);


    int x;
    printf("enter the number : ");
    scanf("%d",&x);
    printf("output: %d\n",10*x);
    return 0;
}