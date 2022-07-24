#include <stdio.h>

int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main()
{
    int n, i = 0, c;
    scanf("%d", &n);
    printf("Fibonacci series - ");
    for (c = 1; c <= n; c++)
    {
        printf("%d ", Fibonacci(i));
        i++;
    }
    return 0;
}
