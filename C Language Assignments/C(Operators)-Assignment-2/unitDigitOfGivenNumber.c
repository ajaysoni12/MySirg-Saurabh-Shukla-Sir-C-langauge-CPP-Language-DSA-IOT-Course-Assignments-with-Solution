#include <stdio.h>
int main()
{
    int num; 
    printf("Input a number: "); 
    scanf("%d",&num); 
    int unit_digit = num%10; 
    printf("Unit digit is: %d",unit_digit); 
    return 0;
}