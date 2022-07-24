#include <stdio.h>
void naturalNum(int n)
{
    if (n > 0)
    {
        naturalNum(n - 1);
        printf("%d ", 2*n-1);
    }
}
int main()
{
    int n; 
    printf("Enter the value: ");
    scanf("%d",&n);
    naturalNum(n);
    return 0;
}