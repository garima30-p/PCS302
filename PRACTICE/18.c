#include <stdio.h>
typedef struct queue{
    int front, size , rear;
    int *arr;
}que;
void create(que **q, int size){
    (*q)->size=size;
    (*q)->arr=(int*)malloc(sizeof(int)*size);
    (*q)->front=(*q)->rear=-1;

}
void enqueue(que **q, int val){
    if((((*q)->rear)%(*q)->size)+1 >=(*q)->front){
        printf("queue overflow..");
        return;
    }
    (*q)->arr[(*q)->rear]=val;
    (*q)->rear=((*q)->rear%(*q)->size)+1;
}
int dequeue(que **q){
    if((*q)->front == (*q)->rear){
        (*q)->front = (*q)->rear =-1;
        printf("queue underflow.."); return  0;
    }
    int x;
    x= (*q)->arr[(*q)->front];
    (*q)->front=((*q)->front % (*q)->size)+1;
    return x;
}
int isempty(que *q){
    if(q->front == -1){
        return 1;
    }
    return 0;
}
int isfull(que *q){
    if((q->rear % q->size)+1 >=q->front)
        return 1;
        return 0;

}

int main(){
    
    return 0;
}