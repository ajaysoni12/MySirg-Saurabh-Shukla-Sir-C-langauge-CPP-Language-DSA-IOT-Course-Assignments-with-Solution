#include <stdio.h>
int main()
{
    int n;
    printf("How many number sum you want to print: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i;
    printf("Sum is %d\n", sum);
    return 0;
}