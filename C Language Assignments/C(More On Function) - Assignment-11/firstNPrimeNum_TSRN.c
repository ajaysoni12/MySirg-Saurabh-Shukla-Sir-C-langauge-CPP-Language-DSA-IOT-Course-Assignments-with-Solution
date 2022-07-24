#include <stdio.h>
#include <math.h>
int firstNPrime(int n)
{
    int i = 1, j;
    while (n)
    {
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
                break;
        }
        if (j - 1 == i / 2)
        {
            printf("%d ", i);
            n--;
        }
        i++;
    }
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    firstNPrime(n); 
    return 0;
}