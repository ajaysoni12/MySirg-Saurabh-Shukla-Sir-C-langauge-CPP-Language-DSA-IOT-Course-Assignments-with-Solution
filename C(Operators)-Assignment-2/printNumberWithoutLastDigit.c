#include <stdio.h>
int main()
{
    int num; 
    printf("Input a number: "); 
    scanf("%d",&num); // 538
    int userNumberWithoutLastDigit = num / 10; 
    printf("User number: %d",userNumberWithoutLastDigit); 
    return 0;
}
