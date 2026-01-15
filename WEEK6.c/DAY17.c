#include <stdio.h>
#include <stdlib.h>


void push{
int x;
while(!empty(&q1)){
    x=dequeue(&q1);
    enqueue(&q2,x);
}
enqueue(&q1,val);
x=dequeue(&q1);
printf("%d",x);
}
void pop{
    int x=dequeue(&q1);
    printf("%d",x);
}
int main(){
    
    return 0;
}