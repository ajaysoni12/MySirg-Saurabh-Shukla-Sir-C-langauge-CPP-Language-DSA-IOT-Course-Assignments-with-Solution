#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Enter a two number: ");
    scanf("%d%d", &num1, &num2); // 1,2
    printf("Before swap: a = %d,b = %d", num1, num2);
    num1 = num1 + num2; // 3
    num2 = num1 - num2; // 1
    num1 = num1 - num2; // 2
    printf("\nAfter swap: a = %d,b = %d", num1, num2);
    return 0;
}