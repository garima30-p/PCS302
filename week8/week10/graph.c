#include <stdio.h>
#include <stdlib.h>



int main(){
    int n,e;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("enter the number of edges: ");
    scanf("%d",&e);
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j]=0;
        }
        
    }
    
for (int i = 0; i < e; i++)
{
   int u,v;
   printf("enter the source: ");
   scanf("%d",&u);
   printf("enter the destination: ");
   scanf("%d",&v);
   mat[u][v]=1;
   mat[v][u]=1;

}

for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           printf("%d",mat[i][j]);
        }
        
    }


    return 0;
}