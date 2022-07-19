#include<stdio.h>
int main()
{
    int dayNum; 
    printf("Enter the day number of the week: "); 
    scanf("%d",&dayNum); 
    switch(dayNum)
    {
        case 1: 
           printf("Today is monday!"); 
           break; 
        case 2: 
           printf("Today is Tuesday!"); 
           break; 
        case 3: 
           printf("Today is Wednesday!"); 
           break; 
        case 4: 
           printf("Today is Thursday!"); 
           break; 
        case 5: 
           printf("Today is Friday!"); 
           break; 
        case 6: 
           printf("Today is Saturday!"); 
           break; 
        case 7: 
           printf("Today is Sunday!"); 
           break; 
        default: 
           printf("Invalid week number!"); 

    }
    return 0;  
}