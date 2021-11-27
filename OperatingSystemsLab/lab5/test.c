#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define NPRO 100
struct elem{
    long long int procid;
    int prio;
};

struct prio_queue{
    struct elem heap[NPRO+1];
    int size;
};

void heap_start(struct prio_queue * p) {
    p->size = 0;
    struct elem m;
    m.procid = 0;
    m.prio = INT_MIN;
    p->heap[0] = m;
	// p->size++;
}

int pqEmpty(struct prio_queue * p) {
    return p->size ==0;
}

int pqFull(struct prio_queue *p) {
    return (p->size==NPRO);
}
void heapifymX(int index,struct prio_queue *p){
    if(index == 0){
        return ;
    }
    int li = 2*index;
    int ri = 2*index+1;
    int largest = index;
    if(li<=p->size && p->heap[largest].prio < p->heap[li].prio){
        largest = li;
    }if(ri<= p->size && p->heap[largest].prio<p->heap[ri].prio){
        largest = ri;
    }
    if(largest != index){
        struct elem temp = p->heap[largest];
        p->heap[largest] = p->heap[index];
        p->heap[index] = temp;
        heapifymX(largest,p);
    }
}
void heapifyX_arr(struct prio_queue * p){
    int a = p->size/2;
    for(int i=a;i>-1;i--){
        heapifymX(i,p);
    }
}

void pqPush(struct prio_queue * p,struct elem e) {
	p->heap[++p->size] = e;
    heapifyX_arr(p);
}


struct elem pqPop(struct prio_queue * p) {
    int index = 1;
    // p->size--;
    struct elem temp = p->heap[index];
    p->heap[index] = p->heap[p->size];
    p->heap[p->size--] = temp;
    heapifyX_arr(p);
    return temp;
}


int main(int argc , char * argv[]) {
    // char value[3400];
    // int n;
    // scanf("%d",&n);
    // sprintf(value , "the value you entered is %d %d and the value I entered is %d %d ",n,n,n+1,n+1);
    // printf("%s\n",value);
    struct prio_queue p;
    heap_start(&p);
    
    for (int i =0;i<5;i++) {
        struct elem e;
        e.procid = 0;
        e.prio = i+1;
        pqPush(&p,e);
    }
    // pqPush(&p,e);
    // pqPush(&p,e);
    // pqPush(&p,e);
    // pqPush(&p,e);
    for (int i =0;i<=p.size;i++ ){
        printf("%d ",p.heap[i].prio);
    }

    struct elem t = pqPop(&p);
    printf("\n%d\n",t.prio);
    for (int i =0;i<=p.size;i++ ){
        printf("%d ",p.heap[i].prio);
    }
    return 0;
}