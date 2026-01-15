#include <stdio.h>

#define MAX 100

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
    int n;
    int matrix[MAX][MAX], rotated[MAX][MAX];

    
    scanf("%d", &n);

 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

   
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotated[j][n - 1 - i] = matrix[i][j];

 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", rotated[i+3][j+3]);
        printf("\n");
    }
    }

    return 0;
}
