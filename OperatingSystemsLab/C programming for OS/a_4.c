#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define largevalue 100000

int main(){

    char * name[largevalue];
    char * namer;
    
    char * history[largevalue];

    
    // namer = malloc(34*sizeof(char));
    // int i =0;
    // namer[i++] = getchar();

    // while(namer[i-1]!='\n'){
    //     namer[i++] = getchar();
    // }
    // namer[i-1] = '\0';

    // printf("%s \n",namer);
    // for(int i =0;i<10;i++){
    //     int j =0;
    //     name[i] = malloc(largevalue*sizeof(char));
    //     name[i][j++] = getchar();
    //     while(name[i][j-1]!='\n'){
    //         name[i][j++] = getchar();
    //     }
    //     name[i][j] = '\0';
    // }
    // // int i =0;
    // // name[i++] = getchar();
    // // while(name[i-1] != '\n'){
    // //     name[i++] = getchar();
    // // }

    // // name[i-1] = '\0';
    // printf("-----------------now printing the array---------------------\n");
    // for(int i =0;i<10;i++){
    //     printf("%s",name[i]);
    // }



    // printf("%s %s \n",name,namer);

    // strcpy(name,namer);

    // printf("%s %s \n",name,namer);
    return 0;
}