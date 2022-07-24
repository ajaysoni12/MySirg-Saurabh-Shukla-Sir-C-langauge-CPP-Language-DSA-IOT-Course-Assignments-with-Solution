#include <stdio.h>
int fun(int n)
{
    if (n == 0)
        return 0;
    return n%10 + fun(n/10);
}
int main()
{
    int n;
    printf("Enter the value: ");
    scanf("%d", &n);
    printf("Sum is: %d", fun(n));
    return 0;
}