#include <stdio.h>
#include <stdlib.h>
int sumOfNValues(int n)
{
    int sum = 0;
    int *ptr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Values: ", i + 1);
        scanf("%d", (ptr + i));
        sum += *(ptr + i);
    }
    free(ptr); // relise dma memory
    return sum;
}
int main()
{
    int n;
    printf("How many values you want to enter: ");
    scanf("%d", &n);
    int sum = sumOfNValues(n);
    printf("\nSum of %d Values is: %d", n, sum);

    return 0;
}