#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<dirent.h>
#include <sys/stat.h>
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define MAX_SIZE 10000
#define clear() printf("\033[H\033[J")

char **tokenize(char *line)
{
  char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
  char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
  int i, tokenIndex = 0, tokenNo = 0;

  for(i =0; i < strlen(line); i++){

    char readChar = line[i];

    if (readChar == ' ' || readChar == '\n' || readChar == '\t'){
      token[tokenIndex] = '\0';
    if (tokenIndex != 0){
        tokens[tokenNo] = (char*)malloc(MAX_TOKEN_SIZE*sizeof(char));
        strcpy(tokens[tokenNo++], token);
        tokenIndex = 0; 
      }
    } else {
      token[tokenIndex++] = readChar;
    }
  }
 
  free(token);
  tokens[tokenNo] = NULL ;
  return tokens;
}

int main(int argc , char * argv[]){
    char * line;
    char * history[MAX_SIZE];
    char **tokens;
    char fileline[MAX_INPUT_SIZE];
    int i = 0;

    
    DIR * dp;
    struct dirent * dirp;
    dp = opendir(".");

    while((dirp = readdir(dp))!= NULL){
        printf("%s %ld %ld %d %d\n",dirp->d_name,dirp->d_ino , dirp->d_off,dirp->d_reclen,dirp->d_type);
    }

    
}

FILE * fp;
        fp = fopen("history_file.txt","a");

        if (fp == NULL){
            printf("error opening file \n");
        } else {
            
        }