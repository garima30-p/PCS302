// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     int data;
//     struct node*prev;
//     struct node*next;
// };
// struct node* create(int k){
//     struct node *temp=(struct node*)malloc(sizeof(struct node));
//     if(temp==NULL){
//         printf("error");
//         return NULL;
//     }
//     temp->data=k;
//     temp->prev=NULL;
//     temp->next=NULL;
//     return 
// }

#include <stdio.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node * create(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertatbegin(struct node** head, int data){
        node* temp=create(data);
        if((*head)==NULL){
            (*head)=temp;
            return;
        }
        (*head)->next=temp;
        temp->prev =(*head);
        (*head)=temp;


}
 
void insertatend(struct node **tail, int data, struct node** head){
    node *temp=create(data);
    if((*tail)==NULL){
        (*tail)=(*head)=temp;
    }
    else{
        temp->prev=*tail;
        (*tail)->next=temp;
        (*tail)=temp;
    }
}

void insertatk(struct node **head, int data, int k){
    node *temp=create(data);
    if((*head)==NULL){
        printf("not found");
        return;   
    }
    if(k==1){
        insertatbegin(data);
    }
    if(k==size()++){
        insertatend(data);
    }
    for (int i = 0; i < k-1; i++)
    {
        temp=temp->next;
    }
}

void reverse(struct node**head,struct node **tail){
        while(curr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
}
int main(){
    
    return 0;
}