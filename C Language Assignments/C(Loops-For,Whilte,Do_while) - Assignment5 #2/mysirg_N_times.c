#include <stdio.h>
int main()
{
    int n;
    printf("How many times you want to print MySirG on the screen: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        printf("MySirG\n");
    return 0;
}