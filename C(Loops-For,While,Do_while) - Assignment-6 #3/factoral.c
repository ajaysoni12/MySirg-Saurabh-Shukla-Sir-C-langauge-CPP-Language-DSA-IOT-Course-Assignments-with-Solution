#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number, for print factoral of these number: ");
    scanf("%d", &n);
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    printf("%d number factoral is: %d", n, fact);
    return 0;
}