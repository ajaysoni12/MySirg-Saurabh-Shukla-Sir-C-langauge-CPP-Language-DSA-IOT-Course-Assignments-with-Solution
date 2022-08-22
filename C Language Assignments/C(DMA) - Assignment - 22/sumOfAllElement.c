#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, sum = 0;
    printf("How many element u want to enter: ");
    scanf("%d", &n);
    int *ptr = (int *)malloc(sizeof(int) * n);
    printf("Input %d Element: ", n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter %d Element: ", i + 1);
        scanf("%d", (ptr + i));
        sum += *(ptr + i);
    }
    printf("\nsum is %d", sum);
    return 0;
}