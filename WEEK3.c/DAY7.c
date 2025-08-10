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
 //   return st->top+1;
//}
void display(struct stack  *st){
    for(int i=st->top;i>=0;i--){
        printf("the element st %d index is %d\n",i,st->s[i]);
        
    }
}
void size(struct  stack *st){
    
    printf("the size of stack is:%d\n",st->size);
}
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
void pop(struct stack *st){
    int x;
    if(st->top==-1){
        printf("stack underflow\n");
       return;
    }
    else{
        x=st->s[st->top];
        st->top--;
        printf("deleted %d\n",x);
    }
  

}
void isempty(struct stack  *st){
    if(st->top==-1)
    printf("stack is empty\n");
    else
    printf("stack is not empty\n");
}


int main(){
    struct stack s;
    int n,x,k,i,t,u;
    create(&s);
    here:
    printf("enter \n 1.push \n 2.POP\n 3.Display\n 4.size\n 5.empty\n 6.exit\n");
    scanf("%d",&k);
    
    // // input(&s);
    // // traverse(&s);
    // printf("enter the number of elements to push: ");
    // scanf("%d",&n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("enter the %dth elemet to push: ",i+1);
    //     scanf("%d",&x);
    //     push(&s,x);
    // }
    // int y=pop(&s);
    // 
    // display(&s);







switch (k)
{
case 1:
       
    printf("enter the number of elements to push: ");
    scanf("%d",&u);
    for (i = 0; i < u; i++)
    {
        printf("enter the  element to push:");
        scanf("%d",&t);
        push(&s,t);    
    }
    goto here;

case 2:
    printf("enter the number of elements wants to pop: ");
    scanf("%d",&t);
    for ( i = 0; i < t; i++)
    {
        pop(&s);
    }
    goto here;

case 3: 
    display(&s);
    goto here;

case 4:
    size(&s);
    goto here;

case 5:
    isempty(&s);
    goto here;
    
case 6:
    default:
    break;
}

    
    
    return 0;
}








// #include<stdio.h>
// #include<stdlib.h>
// struct stack{
//     int top,cap;
//     char *c;
// };
// struct stack* stack(int size)
// {
//     struct stack *st=(struct stack *)malloc(sizeof(struct stack));
//     st->top=-1;
//     st->cap=size;
//     st->c=(char *)malloc(sizeof(char)*st->cap);
//     return st;
// }
// void push(char ch,struct stack* st)
// {
//     if(st->top==st->cap-1)
//         return;
//     st->top=st->top+1;
//     st->c[st->top]=ch;
// }
// char pop(struct stack* st)
// {
//     if(st->top!=-1)
//     return st->c[st->top--];
// }
// int main()
// {
//     char st[50];
//     printf("ENTER A STRING OF PARANTHESIS:");
//     fgets(st,sizeof(st),stdin);
//     struct stack* stk=stack(strlen(st));
//     for(int i=0;i<strlen(st);i++)
//     {
//         if(st[i]=='('||st[i]=='{'||st[i]=='[')
//         {
//             push(stk,st[i]);
//         }
        
//     }
// }
