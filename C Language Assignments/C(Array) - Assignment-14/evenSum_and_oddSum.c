#include<stdio.h> 
int main()
{
    int arr[10],evenSum=0,oddSum=0;  
    printf("Enter 10 number: \n"); 
    for(int i=0; i<=9; i++)
    {
        printf("Enter %d number: ",i+1); 
        scanf("%d",&arr[i]); 
        if(arr[i]%2==0)
            evenSum+=arr[i]; 
        else 
            oddSum+=arr[i]; 
    }
    printf("\nEven sum of All even element present in array: %d",evenSum); 
    printf("\nOdd sum of All odd element present in array: %d",oddSum); 

    return 0; 
}