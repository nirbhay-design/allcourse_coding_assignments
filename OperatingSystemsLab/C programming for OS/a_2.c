#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void call(int ** arr){
    free (*arr);
}

int main(){
    // int * arr = (int *)malloc(4*(sizeof(int)));
    // int * arr = (int *)malloc(4*sizeof(int));
    // int * arr = (int * )malloc(5*sizeof(int));
    // int arr[5];
    // // int num[4] = {1,2,34,4};
    // // arr = num;
    // // for(int i =0;i<4;i++){
    // //     printf("%d \n",arr[i]);
    // // }
    // for(int i =0;i<5;i++){
    //     scanf("%d",&arr[i]);

    // }
    // for(int i =0;i<5;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");

    // int * arr = malloc(64*sizeof(int));
    // if(arr == NULL) return 1;

    // printf("%d \n",arr[0]);
    // free(arr);
    // scanf("%d",&arr[0]);
    // printf("%d\n",arr[0]);

    
    // printf("%d\n",*arr);
    return 0;
}