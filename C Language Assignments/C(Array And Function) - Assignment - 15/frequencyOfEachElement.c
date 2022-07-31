#include <stdio.h>

void printUniqueElement(int arr[], int arrSize)
{
    // Sort Array
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    // print Unique Element
    int count, i = 0, j;
    while (i < arrSize)
    {
        count = 0;
        for (j = i; j < arrSize; j++)
        {
            if (arr[i] == arr[j])
                count++;
            else
                break;
        }
        printf("%d - %d", arr[i], count);
        i = j;
    }
}

int main()
{
    int arrSize;
    printf("How many numbers you want to enter(both Array): ");
    scanf("%d", &arrSize);

    int arr[arrSize];

    printf("Enter %d Numbers in Array\n", arrSize);
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printUniqueElement(arr, arrSize);

    return 0;
}