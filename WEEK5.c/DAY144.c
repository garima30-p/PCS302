#include <stdio.h>
#include <stdlib.h>
struct queue{
    int data;
    int front,rear;
};
void create(struct queue )





















// #include <stdio.h>
// #include <stdlib.h>

 
// struct queue {
//     int size;
//     int front;
//     int rear;
//     int *q;
// };


// void create(struct queue *qt) {
//     printf("Enter the size of the queue: ");
//     scanf("%d", &qt->size);
//     qt->front = qt->rear = -1;
//     qt->q = (int *)malloc(qt->size * sizeof(int));
// }


// void enqueue(struct queue *qt, int x) {
//     if(qt->rear == qt->size - 1) {
//         printf("Queue overflow\n");
//     } else {
//         qt->rear++;
//         qt->q[qt->rear] = x;
//     }
// }
// int dequeue(struct queue *qt) {
//     int x = -1;
//     if(qt->front == qt->rear) {
//         printf("Queue underflow\n");
//     } else {
//         qt->front++;
//         x = qt->q[qt->front];
//     }
//     return x;
// }


// int isEmpty(struct queue qt) {
//     return qt.front == qt.rear;
// }

// void reverseQueue(struct queue *qt) {
   
//     if(isEmpty(*qt)) {
//         return;
//     }

    
//     int data = dequeue(qt);

    
//     reverseQueue(qt);

    
//     enqueue(qt, data);
// }


// void display(struct queue qt) {
//     if(qt.front == qt.rear) {
//         printf("Queue is empty\n");
//     } else {
//         printf("Queue elements: ");
//         for(int i = qt.front + 1; i <= qt.rear; i++) {
//             printf("%d ", qt.q[i]);
//         }
//         printf("\n");
//     }
// }

// int main() {
//     struct queue qt;
//     int choice, value;

    
//     create(&qt);

//     do {
//         printf("\nMenu:\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("4. Reverse Queue\n");
//         printf("5. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch(choice) {
//             case 1:
//                 printf("Enter an integer to enqueue: ");
//                 scanf("%d", &value);
//                 enqueue(&qt, value);
//                 break;
//             case 2:
//                 value = dequeue(&qt);
//                 if(value != -1) {
//                     printf("Dequeued: %d\n", value);
//                 }
//                 break;
//             case 3:
//                 display(qt);
//                 break;
//             case 4:
//                 reverseQueue(&qt);
//                 printf("Queue reversed.\n");
//                 break;
//             case 5:
//                 printf("Exiting...\n");
//                 break;
//             default:
//                 printf("Invalid choice\n");
//         }
//     } while(choice != 5);

   
//     free(qt.q);

//     return 0;
// }