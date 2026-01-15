#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* next;
	};
struct node *createnew(int val){
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	return temp;
	}
	
void insertatbegin(struct node **head, int val){
	struct node *temp= createnew(val);
	temp->next=*head;
	(*head)=temp;
	
	}

void insertatmid(struct node **head, int val, int i){
	int k=1;
	struct node* t= createnew(val);			
	struct node *temp= *head;
		while(k!=i-1){
			temp=temp->next;
			k++;
			}
			if(k==i-1){
			t->next=temp->next;
			temp->next=t;
			}
			else{
				printf("invalid position");
			}
        }

void insertatend(struct node **head, int val){
	if((*head)==NULL){
	insertatbegin(head, val);
	return;
	}		
	struct node *temp= (*head);
	while(temp->next!=NULL){
		temp=temp->next;
		}	
		struct node *newNode=createnew(val);
        temp->next= newNode;
	}

// int md(struct node *head){
// 	if((*head)==NULL){
// 		printf("list is empty");
// 		}
// 	struct node *slow, *fast;
//  	while(fast!=NULL && fast->next!= NULL){
//  		slow=slow->next;
//  		fast=fast->next->next;
//  		}
//  		printf("%d",slow->data);
//  }
				

void deleteatfront(struct node **head){
    if((*head)==NULL){
        printf("list is empty");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head= NULL;
        return;
    }
    struct node *temp= *head;
    (*head)=(*head)->next;
    free(temp);
}


void deleteatend(struct node **head){
    if((*head)==NULL){
        printf("list is empty");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head= NULL;
        return;
    }
    struct node *temp=*head;
    struct node *prev;
    while (temp->next)
    {
        prev=temp;
        temp= temp->next;
        
    }
    prev->next= NULL;
    free(temp);
    
    
}
void deletefromk(struct node **head, int val){
    if((*head)==NULL){
        printf("list is empty");
        return;
    }
    if((*head)->next == NULL){
        free(*head);
        *head= NULL;
        return;
    }
    val--;
    int k=1;
    
    struct node *temp=*head;
    struct node *prev;
    while (k!=val)
    {
        prev=temp;
        temp= temp->next;
        k++;
        
    }
    if(k==val){
    prev->next=temp->next;
    free(temp);
    }
    else{
        printf("invalid position..");
    }
    
    

}
	
void traverse(struct node *head){
    while(head){
        printf("%d\n",head->data);
        head= head->next; 
    }
}
			
	
	
int main(){
    int t;
    printf("enter the number of test cases: ");
    scanf("%d",&t);
    while(t--)
	{
        int ch;
        printf("enter 1 to insertatbegin\n2 to ")
        struct node *head=NULL;
    insertatbegin(&head, 56);
     insertatbegin(&head,74);
  insertatmid(&head,34,2);
  insertatend(&head,89);
    //printf("%d",head->data);
    traverse(head);
    }
	}