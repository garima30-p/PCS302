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
void size(struct stack (*st))
{

    printf("the size of stack is:%d\n", (st)->size);
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
        printf("\ninserted %c", n);
    }
}
void pop(struct stack(*st))
{
    char x = '\0';
    if ((st)->top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    else
    {
        x = (st)->s[(st)->top];
        (st)->top--;
        printf("deleted %c\n", x);
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
    int max=0;
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    create(&st);

    char ch[100];
    printf("Enter only balanced or unbalanced parentheses: ");
    getchar(); 
    fgets(ch, sizeof(ch), stdin);

    for (int j = 0; ch[j] != '\0'; j++)
    {
        if (ch[j] == '(' || ch[j] == '{' || ch[j] == '[')
        {
            push(st, ch[j]);
        }
        else if (ch[j] == ')' || ch[j] == '}' || ch[j] == ']')
        {
            if (isempty(st))
            {
                printf("\n=== Unbalanced ===\n");
                free(st->s);
                free(st);
                return 0;
            }

            char topChar = st->s[st->top];
            if ((ch[j] == ')' && topChar == '(') ||
                (ch[j] == '}' && topChar == '{') ||
                (ch[j] == ']' && topChar == '['))
            {
                pop(st);
                max++;
            }
            
            else
            {
                printf("\n=== Unbalanced ===\n");
                
                free(st->s);
                free(st);
                return 0;
            }
        }
    }

    if (isempty(st))
        printf("\n=== Balanced ===\n");
    else
        printf("\n=== Unbalanced ===\n");

   
    printf("Length of the longest valid parentheses: %d",max*2);

    free(st->s);
    free(st);
    return 0;
}
