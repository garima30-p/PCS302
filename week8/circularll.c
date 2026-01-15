#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

node* create(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next =NULL;
    return temp;
}

void insertatfront(struct node **head, int data){
    node *temp=create(data);
    if((*head)==NULL){
        (*head)=temp;
        (*head)->next = (*head);
        return;
    }
    node *t=(*head);
    while(t->next!=(*head)){
        t=t->next;
    }
    t->next=temp;
    temp->next=(*head);
    (*head)=temp;
}

void insertatend(node ** head, int data){
    node *temp=create(data);
    if((*head)==NULL){
        (*head)=temp;
        (*head)->next = (*head);
        return;
    }
    node *t=(*head);
    while(t->next!=(*head)){
        t=t->next;
    }
    t->next=temp;
    temp->next=(*head);
    
}

// void InsertIntermediate(node **head, int k, int p) {
//     if (p < 1 || p > Size() + 1) {
//         printf("Position out of range.\n");
//         return;
//     }
//     if (p == 1) {
//         InsertFront(k);
//         return;
//     }
//     if (p == Size() + 1) {
//         InsertEnd(k);
//         return;
//     }
//     node* newNode = Create(k);
//     node* temp =(*head);
//     for (int i = 1; i < p - 1; i++) {
//         temp = temp->next;
//     }
//     newNode->next = temp->next;
    
//     temp->next = newNode;
// }


void traverse(node *temp){
    node* t=temp;
    while(t!=temp){
        printf("data is: %d\n", t->data);
        t=t->next;
    }
}

void deletefront(node **head){
    if((*head)==NULL){
        printf("empty list");
        return;
    }
    if((*head)->next==NULL){
        node *temp=(*head);
        (*head)=NULL;
        free(temp);
        return;
    }
    node *temp2=(*head);
    while(temp2->next!=(*head)){
        temp2=temp2->next;
    }    
    temp2->next=(*head)->next;
    node *temp=(*head);
    (*head)=(*head)->next;
    free(temp);
}

void deleteend(node **head){
    if((*head)==NULL){
        printf("list is empty");
        return;
    }
    if((*head)->next==NULL){
        node *temp=(*head);
        (*head)=NULL;
        free(temp);
        return;
    }
    node *prev=NULL;
    node *top2=(*head);
    while(top2)
}

node *concat(node* head1, node* head2){
    node *temp1=head1;
    node *temp2=head2;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL)
    return head1;

    while(temp1->next!=head1){
        temp1=temp1->next;
    }
    while(temp2->next!=head2){
        temp2=temp2->next;
    }
    temp2->next=head1;
    temp1->next=head2;
    return head1;
}














int main(){
       int n;
       printf("enter the data to add on the head: ");
       scanf("%d",n);
       node* head= create(n);
       head->next=head;
    //    insertatfront(&head, 657);
    traverse(head);
    
    return 0;
}