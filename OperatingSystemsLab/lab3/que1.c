#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define maxsize 10000
int main(int argc , char * argv[]){        
    FILE * fp;
    char filecontent[maxsize];
    if (argc == 2) {
        fp = fopen(argv[1],"r");
        int i =0;
        char c = fgetc(fp);
        filecontent[i++] = c;
        while (c != EOF) {
            c = fgetc(fp);
            filecontent[i++] = c;
        }
        filecontent[i-1] = '\0';
        fclose(fp);
    }

    // printf("%s \n",filecontent);
    int len = 0;
    int arr[maxsize];
    char * num = strtok(filecontent," ");
    while (num != NULL){
        arr[len++] = atoi(num);
        num = strtok(NULL," ");
    }

    printf("printing the numbers \n");
    for(int i =0;i<len;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");
    return 0;
}