#include <stdio.h>
#include <math.h>

int min(int a,int b){
    if(a>b)
    return b;
    return a;
}
int abs(int x){
    if(x<0){
        x=x*(-1); 
    }
    return x;
}
int ms(int arr[],int n,int x,int y){
    int i=0,p=-1,mini=__INT_MAX__;
    for ( i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
           if(arr[i]==x && arr[j]==y || arr[j]==x && arr[i]==y){
           
            mini=min(mini,abs(i-j));

        }
        }
        
    }
    if(mini==__INT_MAX__)
    return 0;
    return mini;
}

int main(){
    int t,x,y;
    printf("enter number of test cases: ");
    scanf("%d",&t);
    while(t--){
     int n, i;
    printf("enter the number of elements in the array:");
    scanf("%d", &n);
    printf("enter values of a and b: ");
    scanf("%d %d",&x,&y);
    
    int arr[n];
    for (i = 0; i < n; i++)
    {
        printf("enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }
   int k=ms(arr,n,x,y);
   printf("%d",k);
   printf("\n");
 }
    return 0;
}