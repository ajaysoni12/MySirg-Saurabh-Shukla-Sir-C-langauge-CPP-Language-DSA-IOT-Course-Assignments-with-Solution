#include <stdio.h>
int hcf(int a, int b)
{
    if (a == b)
        return a;
    else if (a % b == 0)
        return b;
    else if (b % a == 0)
        return a;
    if (a > b)
        return gcd(a % b, b);
    else
        return gcd(a, b % a);
}
int main()
{
    int x, y;
    printf("Enter two number: ");
    scanf("%d%d", &x, &y);
    printf("hcf is: %d", hcf(x, y));
    return 0;
}