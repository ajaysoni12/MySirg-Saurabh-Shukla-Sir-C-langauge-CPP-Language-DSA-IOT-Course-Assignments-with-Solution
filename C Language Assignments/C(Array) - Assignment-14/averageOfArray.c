#include<stdio.h> 
int main()
{
    int arr[10],sum=0;  
    printf("Enter 10 number: \n"); 
    for(int i=0; i<=9; i++)
    {
        printf("Enter %d number: ",i+1); 
        scanf("%d",&arr[i]); 
        sum = sum + arr[i]; 
    }
    printf("\nAverage all Element in Array is: %.2f",sum/10.0f); 

    return 0; 
}