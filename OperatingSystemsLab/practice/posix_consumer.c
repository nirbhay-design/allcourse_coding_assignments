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
    shm_fd = shm_open(name,O_RDONLY,0666);

    // ftruncate(shm_fd,size);
    void * ptr;

    ptr = mmap(0,size,PROT_READ,MAP_SHARED,shm_fd,0);

    printf("%s",(char *)ptr);
    
    shm_unlink(name);

    
    return 0;
}