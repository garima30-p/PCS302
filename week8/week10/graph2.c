#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // it(!temp) return NULL;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void addedge(struct node *adj[], int u, int v)
{
    struct node *temp = createnode(v);
    temp->next = adj[u];
    adj[u] = temp;

    struct node *temp2 = createnode(u);
    temp2->next = adj[v];
    adj[v] = temp2;
}

void bfs(struct node *head[], int s, int n)
{
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    int q[n];
    int rear = 0, front = 0;
    vis[s] = 1;
    q[rear++] = s;
    while (front < rear)
    {
        int node = q[front++];
        printf("%d\n", node);
        struct node *temp = head[node];
        while (temp)
        {
            if (!vis[temp->data])
            {
                vis[temp->data] = 1;
                q[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}


void freenodes(struct node *head[], int n) {// no needa write it
    for (int i = 0; i < n; i++) {
        struct node *temp = head[i];
        while (temp) {
            struct node *next = temp->next;
            free(temp);
            temp = next;
        }
        head[i] = NULL; // optional: reset pointer
    }
    printf("Successfully freed all nodes...\n");
}

void dfs(struct node* head[],int s,int vis[]){
    vis[s]=1;
    printf("%d\n",s);
    struct node* temp=head[s];
    while(temp){
        if(!vis[temp->data]){
            dfs(head,temp->data,vis);
        }
        temp=temp->next;
    }

}

int main()
{
    int n, e;
    printf("enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    struct node *head[n];
    for (int i = 0; i < n; i++)
    {
        head[i] = NULL;
    }

    for (int i = 0; i < e; i++)
    {
        int u, v;
        printf("enter source and destination: ");
        scanf("%d %d", &u, &v);
        addedge(head, u, v);
    }
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i]=0;
    }
    printf("dfs traversal is:\n");
    dfs(head,0,vis);
    printf("bfs traversal is:\n");
    bfs(head, 0, n);
    freenodes(head,n);
}