#include <stdio.h>
int fun(int n)
{
    if (n == 1)
        return 1;
    return n * fun(n-1);
}
int main()
{
    int n;
    printf("Enter the value: ");
    scanf("%d", &n);
    printf("Sum is: %d", fun(n));
    return 0;
}