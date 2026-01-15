#include <stdio.h>
#include <stdlib.h>
struct stack{
    int top1,top2, size;
    int *arr;

};
void createnew(struct stack **st){
  printf("enter the size of the stacks: ");
  scanf("%d",&((*st)->size));
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
    int  t;
    printf("enter the number of test cases:");
    scanf("%d",&t);
    while(t--){
    struct  stack *st=(struct stack*)malloc(sizeof(struct stack));
    createnew(&st);
    int choice,num,val;
    printf(" Press:\n1 to push in stack 1\n2 to pop from stack 1\n3 to push in stack 2\n4 to pop from stack 2\n5 to exit");

    switch (choice)
    {
    case 1:
        printf("enter the number of elements to push in stack 1: ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
            printf("enter the %d value:",i+1);
            push1(&st,val);
        }
        
        break;
    case 2:
        printf("enter the number of elements to push in stack 1: ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
            pop1(&st);
        }
        
        break;
    case 3:
        printf("enter the number of elements to push in stack 2: ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
            printf("enter the %d value:",i+1);
            push2(&st,val);
        }
        
        break;
    case 4:
        printf("enter the number of elements to push in stack 1: ");
        scanf("%d",&num);
        for (int i = 0; i < num; i++)
        {
            pop2(&st);
        }
        
        break;
    case 5:
        printf("exiting..");
        free(st);
        break;
        
    default:
        break;
    }
    free(st);
   
    }
    return 0;
}