#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;  
};

struct node* createnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(!temp) return NULL;
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void addedge(struct node*a [],int src,int dest){
    struct node* temp=createnode(dest);
    temp->next=a[src];
    a[src]=temp;
    struct node* temp2=createnode(src);
    temp2->next=a[dest];
    a[dest]=temp;
}

void bfs(struct node* a[],int start,int n){
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i]=0;
    }
    
    
}

int main(){
    
    return 0;
}