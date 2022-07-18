/*
      * 
     ***
    *****
   ******* 
  *********
 */

#include <stdio.h>
int main()
{
    int i, j, lines;
    printf("How many lines of triangle you want to print: ");
    scanf("%d", &lines);
    for (i = 1; i <= lines; i++)
    {
        for (int j = 1; j <= 2 * lines - 1; j++)
        {
            if (j >= lines + 1 - i && j <= lines - 1 + i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}