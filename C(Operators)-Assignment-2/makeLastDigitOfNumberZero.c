#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int newNumber = (num/10) * 10; 
    printf("New number is: %d",newNumber); 
    return 0;
}