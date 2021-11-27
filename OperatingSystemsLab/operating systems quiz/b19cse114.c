#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc , char * argv[]){
    int fd[2]; //file descriptor for reading and writing data
    int d = pipe(fd);
    if (d < 0) {
        printf("pipe cannot be created \n");
    }

    int id = fork();

    if (id < 0) {
        printf("fork cannot be done \n");
        return 1;
    }

    else if (id == 0) {
        close(fd[0]);
        char string[2000];
        printf("enter a string : ");
        fgets(string ,2000, stdin);
        string[strlen(string)-1] = '\0'; // dong this because it will contain \n at the end
        int n = strlen(string) + 1;
        write(fd[1],&n,sizeof(int));
        write(fd[1],string,sizeof(char) * n);
        close(fd[1]);
    } else {
        close(fd[1]);  
        char string[2000];
        int n;
        read(fd[0],&n,sizeof(int ));
        read(fd[0],string,sizeof(char) * n);
        close(fd[0]);
        int i =0;
        while (string[i]!='\0') {
            if (string[i] - 'a' >= 0 && string[i] - 'a' <= 25) {
                string[i] = string[i]-'a' + 'A';
            } else if (string[i] - 'A' >=0 && string[i]-'A' <=25) {
                string[i] = string[i] -'A' + 'a';
            }
            i++;
        }

        printf("got here : %s\n",string);
    }


    return 0;
}