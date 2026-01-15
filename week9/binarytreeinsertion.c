#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree{
    int size;
    int *arr;
}treetype;



void create(treetype **tree, int arr[], int n){
    (*tree)= (treetype*)malloc(sizeof(treetype));
    (*tree)->arr= (int*)malloc(sizeof(int)*n);
    (*tree)->size=n;

    for (int i = 0; i < n; i++)
    {
        (*tree)->arr[i]=arr[i];
        
    }
    printf("created successfully..");    
}

void insert(treetype** tree, int val){
    if((*tree)->size>100){
        printf("not enough space..");
        return;
    }
    (*tree)->arr[(*tree)->size++]=val;
    printf("%d inserted in the tree.",val);
}

void display(struct binarytree *tree){
    if (tree->size == 0) {
        printf("Tree is empty.\n");
        return;
    }

    for (int i = 0; i < tree->size; i++) {
        printf("\nParent: %d\n", tree->arr[i]);

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < tree->size)
            printf("  Left child: %d\n", tree->arr[left]);
        else
            printf("  Left child: NULL\n");

        if (right < tree->size)
            printf("  Right child: %d\n", tree->arr[right]);
        else
            printf("  Right child: NULL\n");
    }
}

void preorder(treetype *root,int i){
    if(i>=root->size) return;
    printf("%d",root->arr[i]);
    preorder(root,(2*i+1));
    preorder(root,(2*i+2));
}
int main(){
    treetype *tree=NULL;
    int n;
    printf("enter the number of elements to enter in the tree:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        printf("enter the %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    
    create(&tree,arr,n);
    printf("entre a number to insert in te tree:");
    scanf("%d",&n);
    insert(&tree,n);
    // display(tree); 
    printf("enter the number to traverse: ");
    scanf("%d",&n);
    preorder(tree,0);

}