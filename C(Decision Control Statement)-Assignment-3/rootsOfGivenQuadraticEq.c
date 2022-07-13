#include <stdio.h>
int main()
{
    // D = b^2 - 4*a*c
    int a, b, c;
    printf("Enter quadratic equation cofficent symultanously: ");
    scanf("%d%d%d", &a, &b, &c);
    int d = (b * b) - (4 * a * c);
    if (d > 0)
        printf("Roots are real and distinct");
    else if (d == 0)
        printf("Roots are real and equal");
    else
        printf("Roots are imaginary");
    return 0;
}