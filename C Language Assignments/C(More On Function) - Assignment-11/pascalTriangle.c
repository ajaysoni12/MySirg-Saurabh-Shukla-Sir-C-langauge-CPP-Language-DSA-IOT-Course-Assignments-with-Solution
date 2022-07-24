#include <stdio.h>
int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

void pascalTriangle(int lines)
{
    int k,col; 
    for (int i = 1; i <= lines; i++)
    {
        k = 1,col=0; 
        for (int j = 1; j < 2 * lines; j++)
        {
            if (k && j >= (lines + 1) - i && j <= (lines - 1) + i)
            {
                printf("%d ",fact(i-1)/(fact(i-1-col)*fact(col))); 
                col++; 
                k = 0;
            }
            else
            {
                printf("  ");
                k = 1;
            }
        }
        printf("\n");
    }
}
int main()
{
    int lines;
    printf("How many lines you want to print: ");
    scanf("%d", &lines);
    pascalTriangle(lines);
    return 0;
}