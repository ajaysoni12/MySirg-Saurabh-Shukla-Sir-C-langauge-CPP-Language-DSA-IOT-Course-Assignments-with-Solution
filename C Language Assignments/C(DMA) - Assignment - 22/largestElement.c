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
int largestElement(int *ptr, int n)
{
    int largestElement = -1;
    for (int i = 0; i < n; i++)
    {
        if (largestElement < *(ptr + i))
        {
            largestElement = *(ptr + i);
        }
    }
    return largestElement;
}
int main()
{
    int n;
    printf("How many element u want to enter: ");
    scanf("%d", &n);
    int *ptr;
    ptr = inputElement(n);
    int large = largestElement(ptr, n);
    printf("%d is largest Element", large);
    return 0;
}