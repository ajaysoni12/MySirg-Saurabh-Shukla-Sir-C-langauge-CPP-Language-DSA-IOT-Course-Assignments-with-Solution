#include<stdio.h> 
int main()
{
    int n; 
    printf("How many number u want to enter: "); 
    scanf("%d",&n); 

    int arr[n]; 

    printf("Enter %d number: \n",n); 
    for(int i=0; i<n; i++)
    {
        printf("Enter %d number: ",i+1); 
        scanf("%d",&arr[i]); 
    }
    
    printf("\nIn Noramal Order: "); 
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]); 
    
    printf("\nIn Reverse Order: "); 
    for(int i=n-1; i>=0; i--)
        printf("%d ",arr[i]); 
    

    return 0; 
}
 