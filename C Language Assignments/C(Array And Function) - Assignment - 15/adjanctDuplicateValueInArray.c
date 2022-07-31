#include<stdio.h> 
int firstDValue(int arr[],int arrSize)
{
    for(int i=1; i<arrSize; i++)
        if(arr[i]==arr[i-1])
            return arr[i]; 
    return -1; 
}
int main()
{
    int arrSize,firstDupliValue; 
    printf("How many number you want to enter: "); 
    scanf("%d",&arrSize);
    int arr[arrSize]; 

    printf("Enter %d Number: ",arrSize); 
    for(int i=0; i<arrSize; i++)
        scanf("%d",&arr[i]); 
    
    firstDupliValue = firstDValue(arr,arrSize); 
    if(firstDupliValue!=-1)
        printf("First Adajanct Duplicate value is: %d",firstDupliValue); 
    else 
        printf("No Value hai Duplicate Occurance!"); 

    return 0; 
}