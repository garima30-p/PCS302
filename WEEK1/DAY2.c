#include <stdio.h>

int main(){
    int n, i;
    printf("enter the number of elements in the array:");
    scanf("%d", &n);
    
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int x=0;
    for ( i = 0; i <n; i++)
    {
        x=x^arr[i];
    }
    printf("the element with odd times of occurance is: %d",x);
    
    return 0;
}