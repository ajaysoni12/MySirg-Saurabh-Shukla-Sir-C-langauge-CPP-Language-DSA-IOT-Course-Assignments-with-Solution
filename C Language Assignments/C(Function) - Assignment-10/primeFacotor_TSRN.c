#include <stdio.h>
int primeFactor(int n)
{
    int i,j; 
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            for (j = 2; j <= i / 2; j ++)
            {
                if (i % j == 0)
                    break;
            }
            if (j - 1 == i / 2)
                printf("%d ", i);
        }
    }
}
int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    primeFactor(num);
    return 0;
}