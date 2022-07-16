#include <stdio.h>
int main()
{
    int n;
    printf("Which number table you want to print: ");
    scanf("%d", &n);
    int i = 1;
    while (i <= 10)
    {
        printf("%d\n", i * n);
        i++;
    }
    return 0;
}