#include <stdio.h>
int main()
{
    int row, col, sumOfMatrix = 0;
    printf("Enter Row and Column of Matrix: ");
    scanf("%d%d", &row, &col);

    int matrix[row][col];
    printf("Enter Element in %d*%d Matrix: \n", row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
            sumOfMatrix += matrix[i][j];
        }
    }

    // print Matrix
    printf("Given Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // matrix sum
    printf("Matrix All Element Sum is: %d\n", sumOfMatrix);
    return 0;
}