#include <stdio.h>
#include <math.h>
int prime(int num)
{
    int i; 
    for(i=2; i<sqrt(num); i++)
       if(num%i==0)
        return 0; 
    return 1; 
}
int main()
{
    int num;
    printf("Enter a number: "); // 5
    scanf("%d", &num);
    if (prime(num))
        printf("Prime number");
    else
        printf("Not prime number");
    return 0;
}