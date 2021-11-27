#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//string operations in c;

int main(int argc , char * argv[]){
    // char * val = "nirbhaysharma";
    // char ** value = &val;
    // char * name = "ravisharma";
    
    // printf("%p %p\n",&value,&name);
    // printf("%s , %s \n",*value , name);
    // value = &name;
    // name = "patil";
    // val = "shrihari";
    // printf("%s , %s\n",*value,name);
    // printf("%p %p\n",&*value,&name);

    char value[] ="nirbhaysharma";
    char name[] = "ravisharma";

    printf("%p %p %p %p\n",&value,&name,&*value,&*name);
    printf("%s %s\n",value,name);

    char * vale = name;
    // strcpy(value,name);
    
    printf("%p %p %p %p\n",&value,&name,&*value,&*name);
    printf("%s %s\n",value,name);
    // int arr[6] ={1,2,3,4,5,6};

    // int * myarr = calloc(6,sizeof(int));
    // for(int i =0;i<6;i++){
    //     myarr[i] = 7;
    // }
    
    
    // for(int i=0;i<6;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    // for(int i =0;i<6;i++){
    //     printf("%d ",myarr[i]);
    // }
    // printf("\n");
    // printf("%p ",&arr);
    // printf("%p \n",&myarr);  
    // myarr =arr;

    // for(int i=0;i<6;i++){
    //     printf("%d ",arr[i]);
    // }
    // printf("\n");
    // for(int i =0;i<6;i++){
    //     printf("%d ",myarr[i]);
    // }
    // printf("\n");
    // printf("%p ",&arr);
    // printf("%p \n",&myarr);

}