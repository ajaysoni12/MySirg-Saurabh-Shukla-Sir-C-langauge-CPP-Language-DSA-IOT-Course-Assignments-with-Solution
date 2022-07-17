// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, and so on.
#include <stdio.h>
int main()
{
    int n;
    printf("How many terms you want to print: ");
    scanf("%d", &n);
    int x = 0, y = 1;
    int sum=0; 
    if (n == 1)
        printf("0 "); 
    else if (n == 2)
        printf("1 "); 
    else
    {
        printf("0 1 "); 
        for (int i = 3; i <= n; i++)
        {
            sum = x + y;
            x = y;
            y = sum;
            printf("%d ",sum); 
        }
    }
    return 0;
}