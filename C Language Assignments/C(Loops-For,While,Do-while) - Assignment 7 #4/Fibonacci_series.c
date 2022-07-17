// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, and so on.
#include <stdio.h>
int main()
{
    int n;
    int x = 0, y = 1;
    int sum=0; 
    printf("Enter the value: ");
    scanf("%d", &n);
    if (n == 1)
        printf("%d finbonacci series no. is: %d",n,0); 
    else if (n == 2)
        printf("%d finbonacci series no. is: %d",n,1); 
    else
    {
        for (int i = 3; i <= n; i++)
        {
            sum = x + y;
            x = y;
            y = sum;
        }
        printf("%d finbonacci series no. is: %d",n,sum); 
    }
    return 0;
}