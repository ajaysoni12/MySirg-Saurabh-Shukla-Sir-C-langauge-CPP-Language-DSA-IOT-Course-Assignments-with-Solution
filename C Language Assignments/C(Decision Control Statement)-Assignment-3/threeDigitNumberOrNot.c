#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num > 99 && num < 1000)
        printf("Yes, Three digit number");
    else
        printf("Not,Three digit number");
    return 0;
}