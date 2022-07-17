#include <stdio.h>
int main()
{
    int n;
    printf("How many odd number you want to print in Reverse Order: ");
    scanf("%d", &n);
    for (int i = 2 * n - 1; i >= 1; i -= 2)
        printf("%d ", i);
    return 0;
}