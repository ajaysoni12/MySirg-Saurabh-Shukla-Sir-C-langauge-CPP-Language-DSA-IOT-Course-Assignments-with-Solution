#include <stdio.h>
int main()
{
    int start, end;
    printf("Enter starting and ending range: ");
    scanf("%d%d", &start, &end);
    int i, j, flag = 1;
    for (i = start; i <= end; i++)
    {
        flag = 1;
        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d ", i);
    }
    return 0;
}