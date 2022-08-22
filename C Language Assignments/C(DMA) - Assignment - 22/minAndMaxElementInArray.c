#include <stdio.h>
#include <stdlib.h>
int *inputElement(int n)
{
    printf("Input %d Element: ", n);
    int *ptr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Element: ", i + 1);
        scanf("%d", (ptr + i));
    }
    return ptr;
}
int minAndMaxElement(int *ptr, int n)
{
    int max = -1;
    int min = __INT_MAX__;
    for (int i = 0; i < n; i++)
    {
        if (max < *(ptr + i))
            max = *(ptr + i);

        if (min > *(ptr + i))
            min = *(ptr + i);
    }
    printf("Min Element - %d, Max Element - %d", min, max);
}
int main()
{
    int n;
    printf("How many element u want to enter: ");
    scanf("%d", &n);
    int *ptr;
    ptr = inputElement(n);
    minAndMaxElement(ptr, n);
    return 0;
}