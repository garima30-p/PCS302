#include <stdio.h>

#include <stdio.h>

#define MAX 100

void rotateClockwise(int matrix[MAX][MAX], int n) {
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][k];
            matrix[i][k] = temp;
        }
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("enter the rows/columns:");
    scanf("%d", &n);

    // Input matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("enter element %d%d:",i,j);
            scanf("%d", &matrix[i][j]);
        }
        
    }

    
    rotateClockwise(matrix, n);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
