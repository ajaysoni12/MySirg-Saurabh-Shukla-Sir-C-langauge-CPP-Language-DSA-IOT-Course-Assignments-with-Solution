#include <stdio.h>
int main()
{
    int n;
    printf("How many number u want to enter: ");
    scanf("%d", &n);

    int firstArray[n], secondArray[n];

    printf("Enter %d number in firstArray: \n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &firstArray[i]);
    }

    printf("\nBefore copy element second array contain garbage value: ");
    for (int i = 0; i < n; i++)
        printf("%d ", secondArray[i]);

    for (int i = 0; i < n; i++)
    {
        secondArray[i] = firstArray[i];
    }

    printf("\nAfter copy element second array will be: ");
    for (int i = 0; i < n; i++)
        printf("%d ", secondArray[i]);

    return 0;
}
