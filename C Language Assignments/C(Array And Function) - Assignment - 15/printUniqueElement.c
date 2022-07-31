#include<stdio.h>

void printUniqueElement(int arr[],int arrSize)
{
    int i,j,flag; 
    for(i=0; i<arrSize; i++)
    {
        flag = 1; 
        for(j=0; j<arrSize; j++)
        {
            if(i!=j && arr[i]==arr[j])
            {
                flag = 0; 
                break; 
            }
        }
        if(flag)
            printf("%d ",arr[i]); 
    }
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

    printf("\nAll Unique Element: "); 
    printUniqueElement(arr,arrSize); 

    return 0; 
}