#include <stdio.h>
int fact(int n)
{
    int fact=1; 
    for(int i=1; i<=n; i++)
      fact*=i; 
    return fact; 
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Factorial is: %d",fact(num)); 
    return 0;
}