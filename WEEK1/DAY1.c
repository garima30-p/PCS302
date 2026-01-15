#include <stdio.h>
void rev(int a[],int i,int j)
{
    int  t;
    while(i<j){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
    }
}
int main()
{
    int k, n, i;
    printf("enter total number of times elements of array is rotated and number of elements in the array:");
    scanf("%d %d", &k, &n);
    k=k%n;
    int arr[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    rev(arr,0,k-1);
    rev(arr,k,n-1);
    rev(arr,0,n-1);
    for (i = 0; i < n; i++)
    {
        printf("  %d  ", arr[i]);
    }

    return 0;
}