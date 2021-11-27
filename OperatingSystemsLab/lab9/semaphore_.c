#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;
struct mydata{
    int val;
    int data;
};

void * routine(void * args) {
    sem_wait(&semaphore);
    sleep(1);
    struct mydata * aer = (struct mydata *) args;
    printf("hello from thread %d %d\n",aer->data,aer->val);
    sem_post(&semaphore);
}

int main(int argc , char * argv[]) {
    pthread_t th[4];
    sem_init(&semaphore,0,1);
    for (int i =0;i<4;i++) {
        struct mydata * a = malloc(sizeof(int));
        a->data = i;
        a->val = i+1;
        if (pthread_create(&th[i],NULL,&routine,(void*)a) != 0) {
            _exit(0);
        }
    }
    for (int i =0;i<4;i++) {
        pthread_join(th[i],NULL);
    }
    sem_destroy(&semaphore);
    return 0;
}