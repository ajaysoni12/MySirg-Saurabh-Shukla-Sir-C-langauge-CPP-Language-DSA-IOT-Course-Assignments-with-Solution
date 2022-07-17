#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter a three number: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a > b && a > c)
        printf("Gretest number is: %d", a);
    else if (b > c)
        printf("Gretest number is: %d", b);
    else
        printf("Gretest number is: %d", c);
    return 0;
}