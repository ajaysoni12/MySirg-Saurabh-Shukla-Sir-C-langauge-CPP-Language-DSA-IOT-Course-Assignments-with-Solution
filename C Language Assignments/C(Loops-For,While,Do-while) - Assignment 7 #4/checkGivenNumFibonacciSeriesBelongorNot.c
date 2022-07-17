// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, and so on.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d", &n);
    int x = 0, y = 1;
    int sum = 0, flag = 0;
    if (n == 0 || n == 1)
        flag = 1;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            sum = x + y;
            x = y;
            y = sum;
            if (n == sum)
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag)
        printf("Yup!, it is belong. ");
    else
        printf("Oops!, it is not belong. ");
    return 0;
}