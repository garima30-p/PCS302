#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size, front ,rear;
    int *q;
};
void createone(struct queue *(*que)){
    printf("enter the size of the queue:");
    scanf("%d", (*que)->size);
    (*que)->front=(*que)->rear=-1;
    (*que)->q=(int*)malloc(sizeof(int)*(*que)->size);
    printf("created successfully");
 
}
int enque(struct queue *q, int val){
    if(q->rear==q->size-1){
        printf("overflow");
        return;
        
    }
    q->rear++;
    q->q[q->rear]=val;
}
int dequeue(struct queue ){
    int x;
    if()
}
int main(){
    struct queue *qu;
    createone(&qu);
    free(qu->q);
}