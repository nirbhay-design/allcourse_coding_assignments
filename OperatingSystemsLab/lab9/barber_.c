#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
/*
variables 
condition variables
variables.wait()
variables.signal()
*/
// monitor mymonitor { 

// }
sem_t empchairs;
sem_t filledchairs;
pthread_t barber;
pthread_mutex_t mut,mut1;
void * barberjob(void * args){
    pthread_mutex_lock(&mut);
    printf("barber engaged with %d\n",*(int *)args);
    sleep(5);
    printf("barber done with %d, %d leaves\n",*(int *)args,*(int *)args);
    // sleep(2);
    sem_post(&empchairs);
    sem_wait(&filledchairs);
    pthread_mutex_unlock(&mut);
}
void * routine(void * args){
    while (1){
        int myans;
        sem_getvalue(&empchairs,&myans);
        if (!myans) {       
            printf("customer %d is returning(no chairs left)\n",*(int *)args);  
                // return (void *)NULL;
            sleep(5);
            printf("customer %d has come back after %d mins\n",*(int *)args,5);
            continue;
                // pthread_create(&delivery_thread,NULL,&deliverpizza,(void *)a);
                // pthread_join(delivery_thread,NULL);
        }
        // printf("hi\n");
        sem_wait(&empchairs);
        sem_post(&filledchairs);
        printf("cutsomer %d sits on the chair\n",*(int *)args);
        pthread_mutex_lock(&mut1);
        int *myb = (int*)malloc(sizeof(int));
        *myb = *(int*)args;
        pthread_create(&barber,NULL,&barberjob,(void *)myb);
        pthread_join(barber,NULL);
        pthread_mutex_unlock(&mut1);
        // sleep(6);
        // sem_post(&empchairs);
        // sem_wait(&filledchairs);
        // printf("customer %d leaves\n",*(int *)args);
        int vall;
        sem_getvalue(&filledchairs,&vall);
        if (!vall){
            printf("barber goes to sleep no customers are left\n");
        }
        sleep(55);
    }
}



int main(int argc , char * argv[]) {
    sem_init(&empchairs,0,5);
    sem_init(&filledchairs,0,0);
    pthread_mutex_init(&mut,NULL);
    pthread_mutex_init(&mut1,NULL);
    int * sem_val;
    // pthread_create(&delivery_thread,NULL,&deliverpizza,NULL);
    // pthread_join(delivery_thread,NULL);
    int N = 9;
    pthread_t th[N];
    for (int i =0;i<N;i++) {
        int * a = (int *)malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i],NULL,&routine,(void*)a) != 0) {
            _exit(0);
        }
    }
    for (int i =0;i<N;i++) {
        pthread_join(th[i],NULL);
    }
    sem_destroy(&empchairs);
    sem_destroy(&filledchairs);
    pthread_mutex_destroy(&mut);
    pthread_mutex_destroy(&mut1);
    return 0;
}