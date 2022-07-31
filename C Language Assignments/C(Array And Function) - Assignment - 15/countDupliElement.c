#include<stdio.h>

int countDupliElement(int arr[],int arrSize)
{
    int count=0; 
    // sorting 
    for(int i=0; i<arrSize; i++)
    {
        for(int j=i+1; j<arrSize; j++)
        {
            if(arr[i]<arr[j])
            {
                int temp = arr[i];  
                arr[i] = arr[j]; 
                arr[j] = temp; 
            }
        }   
    }

    // Count_Duplicate_Value
    for(int i=1; i<arrSize; i++)
    {
        if(arr[i]==arr[i-1])
           count++; 
    }
    return count; 
}

int main()
{
    int arrSize; 
    printf("How many number you want to enter: "); 
    scanf("%d",&arrSize);

    int arr[arrSize]; 

    printf("Enter %d Number: ",arrSize); 
    for(int i=0; i<arrSize; i++)
        scanf("%d",&arr[i]); 

    printf("\nTotal Duplicate Value in Array: %d",countDupliElement(arr,arrSize)); 

    return 0; 
}