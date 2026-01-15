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
int empty(struct queue **q){
    if(((*q)->front)==-1){
        return 1;
    }
}
void enqueue(struct queue **q, int val){
    if(((*q)->rear +1)%(*q)->size==(*q)->front){
        printf("overflow");
        return;
    }
    if(empty(q))
    (*q)->rear=(*q)->front=0;
    else{
        (*q)->rear=((*q)->rear+1)%(*q)->size;
    }
}
int dequeue(struct queue **q){
    if((*q)->front==-1){
        printf("underflow condition");
        return 0;
    }
    int x=(*q)->q[(*q)->front];
    if((*q)->rear==(*q)->front)
        (*q)->rear=(*q)->front=-1;
        else{
            (*q)->front=((*q)->front +1)%(*q)->size;
            
        }
    return x;

}
int main(){
    struct queue *q;
    createone(&q);
    int num,val;
    printf("enter the number of elements need to add in the queue: ");
    scanf("%d",num);

    for (int i = 0; i < num; i++)
    {
        printf("enter data to add:");
       enqueue(&q,val);
    }
    
}