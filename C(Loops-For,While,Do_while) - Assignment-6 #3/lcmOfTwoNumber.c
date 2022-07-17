#include <stdio.h>
int main()
{
    int x, y;
    printf("Enter two number, for lcm: ");
    scanf("%d%d", &x, &y);
    int lcm = 1;
    int i = 1;
    while (1)
    {
        if (i % x == 0 && i % y == 0)
        {
            lcm = i;
            break;
        }
        i++;
    }
    printf("LCM is: %d", lcm);
    return 0;
}