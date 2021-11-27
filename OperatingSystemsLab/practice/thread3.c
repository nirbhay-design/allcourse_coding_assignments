#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *routine() {
    pthread_mutex_lock(&mutex);
    printf("Hello borother\n");
    sleep(2);
    printf("thread dead\n");
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char * argv[]) {
    pthread_t th[4];
    pthread_mutex_init(&mutex,NULL);
    for (int i =0;i<4;i++) {
        printf("creating thread %d \n",i);
        pthread_create(&th[i],NULL,&routine,NULL);
        printf("done creating thread %d\n",i);
    }
    for (int i =0;i<4;i++) {
        pthread_join(th[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}