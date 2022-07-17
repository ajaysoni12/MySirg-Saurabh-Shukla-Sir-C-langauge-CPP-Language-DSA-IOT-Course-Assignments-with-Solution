#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int reverseNumber = 0, ct = 0, flag = 1;
    while (n != 0)
    {
        if (n % 10 == 0 && flag)
            ct++;
        else
            flag = 0;
        reverseNumber = reverseNumber * 10 + n % 10;
        n /= 10;
    }
    printf("Reverse number is: ");
    if (ct != 0)
        for (int i = 1; i <= ct; i++)
            printf("0");
    printf("%d", reverseNumber);
    return 0;
}

// 1 2 3 3 * 10 + 2 = 32 * 100 + 1