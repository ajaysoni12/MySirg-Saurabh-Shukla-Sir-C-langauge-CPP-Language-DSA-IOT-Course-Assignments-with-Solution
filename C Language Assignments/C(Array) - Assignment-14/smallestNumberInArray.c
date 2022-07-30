#include<stdio.h> 
int main()
{
    int arr[10],gSum;   
    printf("Enter 10 number: \n"); 
    for(int i=0; i<=9; i++)
    {
        printf("Enter %d number: ",i+1); 
        scanf("%d",&arr[i]); 
    }
    gSum = arr[0]; 
    for(int i=1; i<=9; i++)
    {
        if(gSum>arr[i])
            gSum = arr[i]; 
    }
    printf("\nSmallest number in Array is: %d",gSum); 
    return 0; 
}
 