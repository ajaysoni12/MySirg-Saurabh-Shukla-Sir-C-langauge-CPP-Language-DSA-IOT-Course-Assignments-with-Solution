#include <stdio.h>
int main()
{
    int x, y;
    printf("Enter two number: ");
    scanf("%d%d", &x, &y);
    int *p = &x, *q = &y;
    if (*p > *q)
        printf("Max Num is: %d", *p);
    else
        printf("Max Num is: %d", *q);
    return 0;
}