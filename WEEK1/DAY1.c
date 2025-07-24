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
    for (i = 0; i < n; i++)
    {
        printf("enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    rev(arr,0,k-1);
    rev(arr,k,n-1);
    rev(arr,0,n-1);
    // while (k--)
    // {
    //     t = arr[n - 1];
    //     for (i = n - 1; i >= 1; i--)
    //     {
    //         arr[i] = arr[i - 1];
    //     }
    //     arr[0] = t;
    // }
    
        
        // if(i<k)
        // arr[i]=arr[i+(n-k-1)];
        // else if(i==k)
        // arr[i]=arr[0];
        // else
        // arr[i]=arr[i-k];
   
    
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}