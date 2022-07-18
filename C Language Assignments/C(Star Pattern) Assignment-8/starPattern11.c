/*
 *
 **
 ***
 ****
 *****
 ****
 ***
 **
 *
 */

#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &lines);
    int k = 0;
    for (i = 1; i <= lines; i++)
    {
        i <= ((lines + 1) / 2) ? k++ : k--;
        for (int j = 1; j <= (lines + 1) / 2; j++)
        {
            if (j <= k)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}