#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

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
        close(fd[0]);
        int n,i;
        int arr[10];
        srand(time(NULL));
        n =rand() % 10 + 1;
        for (i = 0;i<n;i++) {            
            arr[i] = rand() % 11;
        }
        write(fd[1],&n,sizeof(int));
        write(fd[1],arr,sizeof(int) * n);
        close(fd[1]);
    } else {
        close(fd[1]);
        int n;
        read(fd[0],&n,sizeof(int));
        int * arr = (int *)malloc(sizeof(int) * n);
        read(fd[0],arr,sizeof(int) * n);
        int ans = 0;
        for (int i =0;i<n;i++) {
            printf("%d ",arr[i]);
            ans += arr[i];
        }
        close(fd[0]);
        printf("\n");
        printf("%d\n",ans);
        wait(NULL);
    }
    return 0;
}