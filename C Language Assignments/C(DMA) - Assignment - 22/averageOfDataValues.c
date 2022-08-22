#include <stdio.h>
#include <stdlib.h>
int main()
{
    int countOfData, sumOfValues = 0;
    float averageOfValues;
    printf("input a number of data values you would like to enter: ");
    scanf("%d", &countOfData);
    int *ptr;
    // ptr = (int *)calloc(countOfData, sizeof(int));
    ptr = (int *)malloc(sizeof(int) * countOfData);
    for (int i = 0; i < countOfData; i++)
    {
        printf("Enter %d value: ", i + 1);
        scanf("%d", (ptr + i));
        sumOfValues += *(ptr + i);
    }

    averageOfValues = sumOfValues / (float)countOfData;
    printf("Average of data values: %.2f", averageOfValues);
    free(ptr); 
    return 0;
}