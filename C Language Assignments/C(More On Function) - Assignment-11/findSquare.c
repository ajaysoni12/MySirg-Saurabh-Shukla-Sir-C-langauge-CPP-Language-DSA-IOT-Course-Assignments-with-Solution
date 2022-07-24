#include <stdio.h>
int square(int n)
{
    return n * n;
}
int main()
{
    int n;
    printf("Enter any number: ");
    scanf("%d", &n);
    printf("Square is: %d", square(n));
    return 0;
}