#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void * routine() {
    printf("hello world\n");
    sleep(2);
}

int main(int * argc , char * argv[]) {
    pthread_t t1,t2;
    if (pthread_create(&t1,NULL,&routine,NULL) != 0) {
        return 1;
    }
    if (pthread_create(&t2,NULL,&routine,NULL) != 0) {
        return 2;
    }
    pthread_join(t1,NULL);// NULL here get the result from the thread;
    pthread_join(t2,NULL);
    return 0;
}   