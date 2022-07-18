/*
123454321
1234 4321
123   321
12     21
1       1
*/

#include <stdio.h>
int main()
{
    int lines;
    printf("Enter how many lines you want to print: ");
    scanf("%d", &lines);
    int k;
    for (int i = 1; i <= lines; i++)
    {
        k = 1;
        for (int j = 1; j <= lines * 2 - 1; j++)
        {
            if (j <= lines + 1 - i || j >= lines - 1 + i)
            {
                if (j <= lines + 1 - i)
                {
                    printf("%d", k++);
                    if(j==lines+1-1)
                       k = j; 
                }
                else
                    printf("%d", --k);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}