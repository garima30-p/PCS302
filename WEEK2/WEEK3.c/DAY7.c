#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int *s;
    int top;
};
void create(struct stack *st){
    printf("enter the size of the stack: ");
    scanf("%d",&st->size);
    st->s=(int*)malloc(sizeof(int)*st->size);
    st->top=-1;

}
// void input(struct stack  *st){
//     for(int i=0;i<st->size;i++){
//         printf("enter %dth element: ",i+1);
//         scanf("%d",&st->s[i]);
//     }
// }
// void traverse(struct stack  *st){
//     for(int i=0;i<st->size;i++){
//         printf("the %dth element is %d\n",i+1,st->s[i]);
        
//     }
// }
void push(struct stack *st,int n){
    if(st->size-1==st->top){
        printf("stack overflow\n");
        return;
    }
    else{
        st->top++;
        st->s[st->top]=n;
        printf("inserted %d\n",n);

    }
}

int main(){
    struct stack s;
    int n,x;
    create(&s);
    // input(&s);
    // traverse(&s);
    printf("enter the number of elements to push: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("enter the %dth elemet to push: ",i+1);
        scanf("%d",&x);
        push(&s,x);
    }
    
    
    return 0;
}