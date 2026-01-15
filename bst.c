#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * left ,*right;
}node;

struct node* createnew(int data){
    struct node* temp=(node*)malloc(sizeof(node));
    if(!temp)return NULL;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void insert(struct node **root,int data){
    if(!(*root)){
        struct node* temp=createnew(data);
        (*root)=temp;
        return;
    }
    if((*root)->data>data) insert(&((*root)->left),data);
    else  insert(&((*root)->right),data);
}

struct node* min(struct node* root){
    while(root && root->left){
        root=root->left;
    }
    return root;
}

void delete(struct node** root,int data){
    if(!(*root))return;
    if((*root)->data>data){
        delete(&((*root)->left),data);
    }
    else if((*root)->data<data) delete(&((*root)->right),data);
    else{
        if(!(*root)->right){
            struct node* temp=(*root)->left;
            free(*root);
            (*root)=temp;
        }
        else if(!(*root)->left){
            struct node* temp=(*root)->right;
            free(*root);
            (*root)=temp;
        }
        else{
            struct node* temp= min((*root)->right);
                (*root)->data=temp->data;
                delete(&((*root)->right),temp->data);
        }
    }
}

void inorder(struct node* root){
    if(!root){
        return;
        }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void freeal(struct node* root){
    if(!root)return ;
    freeal(root->left);
    freeal(root->right);
    free(root);
    
}


int main(){
    
    return 0;
}