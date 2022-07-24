#include <stdio.h>
int fun(int n,int p)
{
    if (p == 0)
        return 1;
    return n * fun(n,p-1);
}
int main()
{
    int n,power;
    printf("Enter the value and it's power: ");
    scanf("%d%d", &n,&power);
    printf("power is: %d", fun(n,power));
    return 0;
}