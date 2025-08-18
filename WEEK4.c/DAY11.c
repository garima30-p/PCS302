#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top1,top2, size;
    int *arr;

};
void createnew(struct stack **st){
  printf("enter the size of the stacks: ");
  scanf("%d",&(*st)->size);
  (*st)->arr=(int*)malloc(sizeof(int)*(*st)->size);
    (*st)->top1=-1;
    (*st)->top2=(*st)->size;
}
void push1(struct stack **st, int val){// only if top1 is lesser than top2 -1;
    if((*st)->top1<(*st)->top2){
        (*st)->top1++;
        (*st)->arr[(*st)->top1]=val;
    }
    else{
        printf("stack overflow");
    }

}
void push2(struct stack **st, int val){// only if top1 is lesser than top2 -1;
    if((*st)->top1<(*st)->top2){
        (*st)->top2--;
        (*st)->arr[(*st)->top2]=val;
    }
    else{
        printf("stack overflow");
    }

}
int pop1(struct stack **st){
    int x;
    if((*st)->top1==-1)
    printf("stack underflow");
    else{
        x=(*st)->arr[(*st)->top1];
        (*st)->top1--;
    }
    return x;

}
int pop2(struct stack **st){
    int x;
    if((*st)->top2==(*st)->size)
    printf("stack underflow");
    else{
        x=(*st)->arr[(*st)->top2];
        (*st)->top2++;
    }
    return x;

}
int main(){
    
    return 0;
}