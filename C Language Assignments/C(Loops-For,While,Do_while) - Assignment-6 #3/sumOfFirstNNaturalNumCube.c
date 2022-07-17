#include <stdio.h>
int main()
{
    int n;
    printf("How many numbers squares sum you want to print: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * i * i;
    printf("%d odd number sum is: %d", n, sum);
    return 0;
}