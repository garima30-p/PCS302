#include <stdio.h>

int main(){
    int t, x, m = -1;
    printf("enter number of test cases: ");
    scanf("%d", &t);
    while (t--)
    {
        int n, i, c = 0;
        printf("enter the number of rows/column:");
        scanf("%d", &n);
        printf("enter values of target: ");
        scanf("%d", &x);

        int arr[n][n];
        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("enter element: ");
                scanf("%d", &arr[i][j]);
            }
        }
        for (i = 0; i < n; i++)
        {
            if ((arr[i][n - 1]) >= x)
            {
                m = i;
                break;
            }
        }
        if (m == -1)
        {
            printf("not present\n");
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (arr[m][i] == x)
                {
                    printf("present\n");
                    c = 1;
                    break;
                }
            }
            if (c == 0)
            {
                printf("not present\n");
            }
        }
    }

    return 0;
}