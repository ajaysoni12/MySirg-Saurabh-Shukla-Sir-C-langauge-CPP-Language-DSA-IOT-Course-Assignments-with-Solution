#include <stdio.h>
int main()
{
    int num, digit;
    printf("Enter a number and also input a digit: ");
    scanf("%d%d", &num, &digit);
    int newNumber = num * 10 + digit;
    printf("New number is: %d", newNumber);
    return 0;
}