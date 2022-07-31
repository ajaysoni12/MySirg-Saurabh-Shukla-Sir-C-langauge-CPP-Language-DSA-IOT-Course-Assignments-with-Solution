#include <stdio.h>
int main()
{
    int a[3][3], b[3][3], sumMatrix[3][3];
    printf("Enter Element in First 3*3 Matrix: \n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    printf("Enter Element in Second 3*3 Matrix: \n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &b[i][j]);

    // Sum of Matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sumMatrix[i][j] = a[i][j] + b[i][j];

    // print First Matrix
    printf("First Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    // print Second Matrix
    printf("Second Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    // print Sum Of Upper Two Matrix
    printf("Sum of Twoa Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", sumMatrix[i][j]);
        printf("\n");
    }
    return 0;
}