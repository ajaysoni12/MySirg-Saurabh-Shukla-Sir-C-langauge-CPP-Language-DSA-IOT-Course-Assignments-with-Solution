#include <stdio.h>
int main()
{
    int row, leftDiagoSum = 0;
    printf("Enter Row of Matrix: ");
    scanf("%d", &row);

    int matrix[row][row];
    printf("Enter Element in %d*%d Matrix: \n", row, row);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            scanf("%d", &matrix[i][j]);

    // find left Diagonal Sum
    for (int i = 0, j = row - 1 - i; i < row; i++, j--)
        leftDiagoSum += matrix[i][j];

    // print Matrix
    printf("Given Matrix: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // right Diagonalls sum
    printf("left Diagonals of Matrix Sum is: %d\n", leftDiagoSum);
    return 0;
}