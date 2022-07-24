#include <stdio.h>
#include <math.h>
void prime(int x, int y)
{
    int i, j;
    for (i = x; i <= y; i++)
    {
        for (j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
                break;
        }
        if (j - 1 == i/2)
            printf("%d ", i);
    }
}
int main()
{
    int a, b;
    printf("Enter the two number: ");
    scanf("%d%d", &a, &b);
    prime(a, b);
    return 0;
}