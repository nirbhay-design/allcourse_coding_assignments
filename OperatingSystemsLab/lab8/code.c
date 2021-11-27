#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

const int N= 5;
pthread_mutex_t mutex;
sem_t chop[5];

int G[10][10];//0-4 process and 5-9 forks

int getright(int n) {
    if (n == 0) {
        return 9;
    } else {
        return n+N-1;
    }
}
void print(){

    for (int i =0;i<2*N;i++) {
        for (int j = 0;j<2*N;j++) {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}

int visited[10];
int dfs(int s){
	visited[s]=1;
	for(int i=0;i<2*N;i++){
		if (i==s) continue;
		if (G[s][i]==1&& visited[i]==0){
			if(dfs(i)) return 1;
		}
		else if(G[s][i]==1&& visited[i]==1){
            printf("%d %d\n",s,i);
			return 1;

		}

	}
    visited[s]=2;

	return 0;
}
int detect_cycle(){
    for (int i = 0;i<2*N;i++) {
        visited[i] = 0;
    }
    for (int i =0;i<2*N;i++){
        if (visited[i]==0) {
			if(dfs(i)) {
                return 1;
            }
            
        }
    }
    return 0;
}

void* philos(void* n){
	int p=*(int*)n;//particular philospher
	// printf("Philospher %d start eating\n",p);
	printf("Philospher %d try to take left chopstick\n",p);
	sem_wait(&chop[p]);
    printf("Philospher %d takes left chopstick\n",p);
    int left = p+N,right = getright(p);
	printf("%d %d\n",left,right);
    pthread_mutex_lock(&mutex);
    G[left][p] = 1;// resource allocated;
    G[p][right] = 1; // wait for right;
    pthread_mutex_unlock(&mutex);
    if (detect_cycle()) {
        printf("Deadlock detected\n");
        // print();
        sem_post(&chop[p]);
        printf("Philospher %d frees left chopstick due to deadlock\n",p);
        G[left][p] = 0;
        pthread_mutex_unlock(&mutex);
        return NULL;
    } 
	printf("Philospher %d try to take right chopstick\n",p);
	int r=(p+1)%N;
	sem_wait(&chop[r]);
	printf("Philospher %d takes right chopstick\n",p);
    pthread_mutex_lock(&mutex);
    G[p][right] = 0;
    G[right][p] = 1;
    pthread_mutex_unlock(&mutex);
	printf("Philospher %d starts eating\n",p);
	sleep(2);
	printf("Philospher %d ends eating\n",p);
	sem_post(&chop[r]);
	printf("Philospher %d frees right chopstick\n",p);
    pthread_mutex_lock(&mutex);
    G[right][p] = 0;
    pthread_mutex_unlock(&mutex);
    // G[p][right] = 0;
	sem_post(&chop[p]);
	printf("Philospher %d frees left chopstick\n",p);
    pthread_mutex_lock(&mutex);
    G[left][p] = 0;
    pthread_mutex_unlock(&mutex);

}




int main(){
    for (int i =0;i<2*N;i++) {
        for (int j = 0;j<2*N;j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0;i<2*N;i++) {
        visited[i] = 0;
    }
    pthread_mutex_init(&mutex,NULL);
	int n;
	int a[N];
	pthread_t T[N];
	for(int i=0;i<N;i++){
		sem_init(&chop[i],0,1);
	}

	for(int i=0;i<N;i++){
		a[i]=i;
		pthread_create(&T[i],NULL,philos,(void*)&a[i]);
	}
	for(int i=0;i<N;i++){
		pthread_join(T[i],NULL);

	}
    pthread_mutex_destroy(&mutex);

    // G[7][2] = 1;
    // G[2][6] = 1;
    // printf("%d\n",detect_cycle());
	return 0;


}