//code to reverse a string using stack:
#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    char *s;
    int top;
};
void create(struct stack **st)
{
    printf("enter the size of the stack: ");
    scanf("%d", &(*st)->size);
    (*st)->s = (char *)malloc(sizeof(char) * (*st)->size);
    (*st)->top = -1;
    printf("created.");
}
void display(struct stack *st)
{
    for (int i = (st)->top; i >= 0; i--)
    {
        printf("the element st %d index is %c\n", i, (st)->s[i]);
    }
}
void size(struct stack *(*st))
{

    printf("the size of stack is:%d\n", (*st)->size);
}
void push(struct stack(*st), char n)
{
    if ((st)->size - 1 == (st)->top)
    {
        printf("stack overflow\n");
        return;
    }
    else
    {
        (st)->top++;
        (st)->s[(st)->top] = n;
        
    }
}
int pop(struct stack(*st))
{
    char x = '\0';
    if ((st)->top == -1)
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        x = (st)->s[(st)->top];
        (st)->top--;
        return x;
        
    }
}
int isempty(struct stack(*st))
{
    if ((st)->top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    create(&st);

    int u,x, i, t = 0, p = 0;
    char ch[100];

    printf("enter your string to be rev:");
    getchar();
    fgets(ch, sizeof(ch), stdin);
    for ( i = 0; ch[i]!=0; i++)
    {
       push(st,ch[i]);
    }
   
        for ( int j = 0; ch[j]!='\0'; j++)
        {
            x=pop(st);
            ch[j]=x;
        }
        
       
   
    puts(ch);

       free(st->s);  
    free(st);     

}