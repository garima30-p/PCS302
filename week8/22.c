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

// void createdll(struct dll **d,int size){
//     (*d)=(struct dll*)malloc(sizeof(struct dll));
//     if(!(*d)) return;
//     (*d)->head=NULL;
//     (*d)->tail=NULL;
//     (*d)->size=size;
//     int val;
//    if(size!=0){
//         printf("enter the data for the head  node: ");
//         scanf("%d",&val);
//         insertfront(val,d);
//     }
//     for (int i = 1; i < size; i++)
//     {
//         printf("enter the data of %d node:", i+1);
//         scanf("%d",&val);
//         insertend(val,d);
//     }

// }

void insertfront(int k, struct dll *d)
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

void insertend(int k, struct dll *d)
{
    struct node *temp = create(k);
    if (d->head == NULL)
    {
        d->head = d->tail = temp;
    }
    else
    {
        d->tail->next = temp;
        temp->prev = d->tail;
        d->tail = temp;
    }
    d->size++;
}

void insertintermediate(int k, struct dll *d, int val)
{
    if (k > d->size || k < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (k == 1)
    {
        insertfront(val, d);
        return;
    }

    struct node *temp = create(val);
    struct node *h = d->head;

    for (int i = 1; i < k - 1; i++)
    {
        h = h->next;
    }

    temp->next = h->next;
    if (h->next != NULL)
    {
        h->next->prev = temp;
    }
    temp->prev = h;
    h->next = temp;

    d->size++;
}

void deletefront(struct dll *d)
{
    if (d->head == NULL)
        return;
    struct node *h = d->head;
    d->head = d->head->next;
    if (d->head != NULL)
    {
        d->head->prev = NULL;
    }
    free(h);
    d->size--;
}

void deleteend(struct dll *d)
{
    if (d->tail == NULL)
        return;
    struct node *t = d->tail;
    if (d->tail->prev != NULL)
    {
        d->tail = d->tail->prev;
        d->tail->next = NULL;
    }
    else
    {
        d->head = NULL;
        d->tail = NULL;
    }

    free(t);
    d->size--;
}
void deleteintermediate(struct dll *d, int p)
{
    if (d->head == NULL || p < 1 || p > d->size)
        return;

    struct node *h = d->head;
    for (int i = 1; i < p; i++)
    {
        h = h->next;
    }
    if (h->prev != NULL)
    {
        h->prev->next = h->next;
    }
    else
    {
        d->head = h->next;
    }

    if (h->next != NULL)
    {
        h->next->prev = h->prev;
    }
    else
    {
        d->tail = h->prev;
    }

    free(h);
    d->size--;
}

int size(struct dll *d)
{
    return d->size;
}

int isempty(struct dll *d)
{
    return d->size == 0;
}

int findmid(struct dll *d)
{
    if (isempty(d))
        return 0;
    if (!d->head->next)
        return d->head->data;
    struct node *fasts = d->head;
    struct node *slow = d->head;
    while (fasts->next != NULL && fasts->next->next != NULL)
    {
        fasts = fasts->next->next;
        slow = slow->next;
    }
    return slow->data;
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

int main() {
    struct dll *list = NULL;
    int choice, val, pos;

    createdll(&list);

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Check if Empty\n");
        printf("9. Find Middle Element\n");
        printf("10. Free Entire List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertfront(val, list);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertend(val, list);
                break;

            case 3:
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertintermediate(pos, list, val);
                break;

            case 4:
                deletefront(list);
                printf("Front node deleted.\n");
                break;

            case 5:
                deleteend(list);
                printf("End node deleted.\n");
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteintermediate(list, pos);
                printf("Node at position %d deleted.\n", pos);
                break;

            case 7:
                display(list);
                break;

            case 8:
                if (isempty(list))
                    printf("List is empty.\n");
                else
                    printf("List is not empty.\n");
                break;

            case 9:
                val = findmid(list);
                if (val)
                    printf("Middle element: %d\n", val);
                else
                    printf("List is empty.\n");
                break;

            case 10:
                freeal(list);
                list = NULL;
                printf("List freed.\n");
                createdll(&list);
                break;

            case 11:
                freeal(list);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}