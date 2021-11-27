#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <limits.h>

int main(int argc ,char * argv[]) {
    int n = 10;
    void * p = &n;

    printf("%d\n",*(int *)p);
    
    
    return 0;
}