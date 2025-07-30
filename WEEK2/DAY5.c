#include <stdio.h>

int main(){
   int t;
    printf("enter number of test cases: ");
    scanf("%d", &t);
    while (t--)
    {int n, i,j, c = 0;
        printf("enter the number of rows/column:");
        scanf("%d", &n);

        int arr[n][n];
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("enter element: ");
                scanf("%d", &arr[i][j]);
            }
        }
            int temp=-1;
            i=0;
            j=n-1;
            while(i<n && j>=0){
                if(arr[i][j]==1){
                temp=i;
                j--;
            }
            else{
                i++;
            }
            }
            printf("the maximum number of 1 appeared in row: %d",temp+1);

    
    return 0;
}
}