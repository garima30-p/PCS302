#include <stdio.h>

int main(){
    int k,n,t,i;
    printf("enter total number of times elements of array is rotated and number of elements in the array:");
    scanf("%d %d",&k,&n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("enter %d element: ",i+1);
        scanf("%d",&arr[i]);

    }
    while(k--){
        t=arr[n-1];
        for (i =n-1; i >=1; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=t;
        
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    
    return 0;
}