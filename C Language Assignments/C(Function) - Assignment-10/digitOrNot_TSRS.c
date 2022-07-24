#include <stdio.h>
int check(int n, int digit)
{
    while (n != 0)
    {
        if (n % 10 == digit)
            return 1;
        n /= 10;
    }
    return 0;
}
int main()
{
    int num, digit;
    printf("Enter the two number: ");
    scanf("%d%d", &num, &digit);
    if (check(num, digit))
        printf("YEs! contain");
    else
        printf("Not! Contain");
    return 0;
}