#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bytes;
    printf("Enter size in bytes for allocating memory dymanically: ");
    scanf("%d", &bytes);
    int *ptr = NULL;
    ptr = (int *)malloc(bytes);
    if (ptr != NULL)
        printf("Memory Allocated Successfull!");
    else
        printf("Memory Error!");
    return 0;
}