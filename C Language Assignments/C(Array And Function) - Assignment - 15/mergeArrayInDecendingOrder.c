#include <stdio.h>

void mergeArary(int a[], int b[], int merge[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        merge[i] = a[i];
        merge[arrSize + i] = b[i];
    }
}
int main()
{
    int arrSize;
    printf("How many numbers you want to enter(both Array): ");
    scanf("%d", &arrSize);

    int a[arrSize], b[arrSize];

    printf("Enter %d Numbers in First Array\n", arrSize);
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &a[i]);

    printf("Enter %d Numbers in Second Array\n", arrSize);
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &b[i]);

    int merge[arrSize * 2]; // store merge arrays element

    mergeArary(a, b, merge, arrSize);

    printf("\nAfter Merging: ");
    for (int i = 0; i < arrSize * 2; i++)
        printf("%d ", merge[i]);

    return 0;
}