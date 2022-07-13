#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter a sides of trinagle: ");
    scanf("%d%d%d", &a, &b, &c);
    if (b + c > a && a + c > b && a + b > c)
        printf("Triagnle is valid!");
    else
        printf("Triangel is not valid!");
    return 0;
}