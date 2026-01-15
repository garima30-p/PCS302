#include <stdio.h>
#include <stdlib.h>
int max=100;
struct binarytree{
    int size;
    int *arr;
};

void CreateTree(struct binarytree** tree, int arr[], int n) {
    (*tree)->size = n;
    for (int i = 0; i < n; i++)
       (*tree)->arr[i] = arr[i];
        printf("created successfully...");
}


void insert(struct binarytree *tree, int x){
    if((*tree)->size>=max){
        printf("overflow..");
        return;
    }
    else{
        (*tree)->arr[(*tree)->size]=x;
        (*tree)->size++;
    }
}

void delete(struct binarytree *tree, int x){
        if(tree->size<=0){
            return;
        }
        int i;
        for (i = 0; i < tree->size; i++)
        {
            if(tree->arr[i]==x) break;
        }
        if(i==tree->size) return;
        else{
            tree->arr[i]=tree->arr[(tree->size--)-1];
            
        }
        
}


void display(struct binarytree *tree){
     if (tree->size == 0) {
        printf("Tree is empty.\n");
        return;
    }


  
    for (int i = 0; i <tree->size; i++)
    {
        printf("parent: %d", tree->arr[i]);
        int left=2*i+1;
        int right =2*i+2;
        if(left<tree->size)
        printf("the left child is: %d", tree->arr[left]);
        else printf("left child is NULL");
        if(right<tree->size)
        printf("the right child is: %d", tree->arr[right]);
        else printf("the right child is NULL");
    }
    
}

int main(){
    int n;
    printf("Enter number of nodes for initial tree: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    struct binarytree *tree;
    CreateTree(&tree, arr,n);
    return 0;
}