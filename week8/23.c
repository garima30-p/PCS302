#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};
struct dll
{
    int size;
    struct node *head, *tail;
};

struct node *create(int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void createdll(struct dll **d)
{
    (*d) = (struct dll *)malloc(sizeof(struct dll));
    if (!(*d))
        return;
    (*d)->head = NULL;
    (*d)->tail = NULL;
    (*d)->size = 0;
}

void insert(int k, struct dll *d)
{
    struct node *temp = create(k);
    if (d->head == NULL)
    {
        d->head = d->tail = temp;
    }
    else
    {
        temp->next = d->head;
        d->head->prev = temp;
        d->head = temp;
    }
    d->size++;
}

void display(struct dll *d)
{
    if (isempty(d))
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = d->head;
    printf("List contents: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeal(struct dll *d)
{
    struct node *p = NULL;
    while (d->head)
    {
        p = d->head;
        d->head = d->head->next;
        free(p);
    }
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
    free(d);
}

void reverse(struct dll* d) {
    if (d->head == NULL || d->head->next == NULL) return;

    struct node *current = d->head;
    struct node *temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = d->head;
    d->head = d->tail;
    d->tail = temp;
}







