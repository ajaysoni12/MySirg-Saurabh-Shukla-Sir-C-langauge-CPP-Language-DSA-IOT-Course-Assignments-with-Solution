#include <stdio.h>
int main()
{
    int num; 
    printf("Enter a number: "); 
    scanf("%d",&num); 
    if(num%3==0 || num%7==0)
      printf("Divisble!"); 
    else 
      printf("Not divisible1"); 
    return 0;
}