#include<stdio.h>
int main()
{
    int monthNum; 
    printf("Enter month number: "); 
    scanf("%d",&monthNum); 
    switch(monthNum)
    {
        case 1: 
        case 3: 
        case 5:
        case 7: 
        case 8: 
        case 10: 
        case 12: 
             printf("31 Days!");
             break;
        case 4: 
        case 6: 
        case 9: 
        case 11: 
             printf("30 Days!"); 
             break;
        case 2: 
             printf("28 or 29 days depont upon year is leap year or not");
             break;
        default:
             printf("wrong value!"); 
    }
    return 0; 
}