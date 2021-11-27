#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Point{
    int x,y;
} point;

point * average(point * a ,point * b){
    point * m = (point *)malloc(sizeof(point));
    m->x = (a->x + b->x) /2;
    m->y = (a->y + b->y ) /2;
    return m;
}
/*
learnings 
pointer needs to be allocated memory 
if already defined size of array then no need to allocate pointer;
if pointer is free then if you store that somewhere it will return garbage value as it is not there anymore in the memory 
instead we can use the copy of the struct to stre it in the pointer;

*/

int main(){
    point arr[1000];
    int i =0;
    while(i<3){
        point * a = (point *)malloc(sizeof(point));
        point * b = (point *)malloc(sizeof(point));
        printf("Enter the corodinates of the first number : ");
        scanf("%d %d",&(a->x),&(a->y));
        printf("Enter the cordinates of the second number: ");
        scanf("%d %d",&(b->x),&(b->y));
        point * myavg = average(a,b);
        printf("%d %d \n",myavg->x , myavg->y);
        arr[i++] = *myavg;
        free(myavg);
        // free(myavg);

    }

    printf("loop breaks now printing inside value of arr \n");
    for(int i =0;i<3;i++){
        printf("%d %d \n",arr[i].x , arr[i].y);
    }
    

    return 0;
}