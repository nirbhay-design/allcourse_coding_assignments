#include <stdio.h>
#include <stdlib.h>

struct str{
    int val;
    int idx;
};

int comp(const void * a , const void * b){
    return ((*((struct str*)a)).val - (*(struct str *)b).val);
}

int main(){
    struct str * arr = malloc(5*sizeof(struct str));
    arr[0].val = 2;
    arr[1].val = 1;
    arr[2].val = 0;
    arr[3].val = 3;
    arr[4].val = 4;
    for (int i = 0;i<5;i++){
        printf("%d ",arr[i].val);
    }
    printf("\n");

    qsort(arr,5,sizeof(struct str),comp);
    for (int i = 0;i<5;i++){
        printf("%d ",arr[i].val);
    }
    printf("\n");
    
    return 0;
}