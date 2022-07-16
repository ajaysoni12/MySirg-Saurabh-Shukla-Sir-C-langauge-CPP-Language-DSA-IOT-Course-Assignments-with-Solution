#include <stdio.h>
int main()
{
    int n;
    printf("How many Natural Number you want to print: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("%d ", i);
    return 0;
}