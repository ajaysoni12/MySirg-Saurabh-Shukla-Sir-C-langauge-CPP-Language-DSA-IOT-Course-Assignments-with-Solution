/*
ABCDEDCBA
ABCD EDCB
ABC   CBA
AB     BA
A       A
*/

#include <stdio.h>
int main()
{
    int lines;
    printf("Enter how many lines you want to print: ");
    scanf("%d", &lines);
    for (int i = 1; i <= lines; i++)
    {
        int k = 'A';
        for (int j = 1; j <= lines * 2 - 1; j++)
        {
            if (j <= (lines + 1) - i || j >= (lines - 1) + i)
            {
                printf("%c", k);
                j < lines ? k++ : k--;
            }
            else
            {
                printf(" ");
                if (j == 4)
                    k--;
            }
        }
        printf("\n");
    }
    return 0;
}