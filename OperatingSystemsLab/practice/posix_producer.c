#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>


int main(int argc , char * argv[]) {
    const int size = 4096;
    const char * name = "0s";
    const char * msg0 = "nirbhay";
    const char * msg1 = "sharma";

    int shm_fd;
    shm_fd = shm_open(name,O_CREAT|O_RDWR,0666);

    ftruncate(shm_fd,size);
    void * ptr;

    ptr = mmap(0,size,PROT_WRITE,MAP_SHARED,shm_fd,0);

    ptr = (char *)ptr;
    sprintf(ptr,"%s",msg0);
    ptr += strlen(msg0);
    sprintf(ptr,"%s",msg1);
    ptr+= strlen(msg1);

    
    return 0;
}