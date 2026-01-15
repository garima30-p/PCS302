// Doubly linked list implementation with basic operations
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

// allocate and initialize a node
node *create_node(int data) {
    node *n = malloc(sizeof(node));
    if (n == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    n->prev = n->next = NULL;
    n->data = data;
    return n;
}

int size_list(node *head) {
    int c = 0;
    for (node *it = head; it != NULL; it = it->next)
        c++;
    return c;
}

void display_forward(node *head) {
    for (node *it = head; it != NULL; it = it->next)
        printf("%d ", it->data);
    printf("\n");
}

void display_backward(node *tail) {
    for (node *it = tail; it != NULL; it = it->prev)
        printf("%d ", it->data);
    printf("\n");
}

void insert_at_begin(node **head, node **tail, int data) {
    node *n = create_node(data);
    if (*head == NULL) {
        *head = *tail = n;
        return;
    }
    n->next = *head;
    (*head)->prev = n;
    *head = n;
}

void insert_at_end(node **head, node **tail, int data) {
    node *n = create_node(data);
    if (*tail == NULL) {
        *head = *tail = n;
        return;
    }
    (*tail)->next = n;
    n->prev = *tail;
    *tail = n;
}

// insert at position k (1-based). allowed k: 1 .. size+1
void insert_at_k(node **head, node **tail, int data, int k) {
    if (k < 1) {
        printf("invalid position %d\n", k);
        return;
    }
    int n = size_list(*head);
    if (k == 1) {
        insert_at_begin(head, tail, data);
        return;
    }
    if (k == n + 1) {
        insert_at_end(head, tail, data);
        return;
    }
    if (k > n + 1) {
        printf("position %d out of range (1..%d)\n", k, n + 1);
        return;
    }
    node *it = *head;
    for (int i = 1; i < k - 1; ++i) // stop at (k-1)th node
        it = it->next;
    node *nnode = create_node(data);
    nnode->next = it->next;
    nnode->prev = it;
    if (it->next)
        it->next->prev = nnode;
    it->next = nnode;
}

void reverse_list(node **head, node **tail) {
    if (*head == NULL)
        return;
    node *orig_head = *head;
    node *curr = orig_head;
    node *new_head = NULL;
    while (curr) {
        new_head = curr;            // last visited becomes new head
        node *next = curr->next;    // save next before clobbering
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }
    *tail = orig_head;
    *head = new_head;
}

void free_list(node *head) {
    while (head) {
        node *next = head->next;
        free(head);
        head = next;
    }
}


void removeduplicata(struct node **head, struct node **tail){
    struct node *temp=(*head);
     while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            node *dup=temp->next;
            temp->next=dup->next;
            if(temp->next!=NULL){
                dup->next->prev=temp;
            }
            else{
                (*tail)=temp;
            }
            
        }
        else{
                temp=temp->next;
            }
     }
}

int main(void) {
    node *head = NULL;
    node *tail = NULL;

    // build list: 10 20 30
    insert_at_end(&head, &tail, 10);
    insert_at_end(&head, &tail, 20);
    insert_at_end(&head, &tail, 30);

    printf("forward: "); display_forward(head);
    printf("backward: "); display_backward(tail);

    insert_at_begin(&head, &tail, 5); // 5 10 20 30
    printf("after insert at begin: "); display_forward(head);

    insert_at_k(&head, &tail, 15, 3); // 5 10 15 20 30
    printf("after insert at pos 3: "); display_forward(head);

    reverse_list(&head, &tail);
    printf("after reverse forward: "); display_forward(head);
    printf("after reverse backward: "); display_backward(tail);

    free_list(head);
    return 0;
}