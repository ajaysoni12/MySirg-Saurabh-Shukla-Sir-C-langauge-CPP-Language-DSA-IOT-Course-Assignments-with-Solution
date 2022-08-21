#include <stdio.h>
void sortArray(int *ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(ptr + i) > *(ptr + j))
            {
                int temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }
}
int main()
{
    int size;
    printf("Enter the array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d Element in array\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    sortArray(arr, size);
    printf("\nAfter Sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}