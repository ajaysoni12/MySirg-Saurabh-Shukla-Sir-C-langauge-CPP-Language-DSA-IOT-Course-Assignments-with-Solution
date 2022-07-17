#include <stdio.h>
int main()
{
    int n;
    printf("How many odd number you want to print: ");
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i += 2)
        printf("%d ", i);
    return 0;
}