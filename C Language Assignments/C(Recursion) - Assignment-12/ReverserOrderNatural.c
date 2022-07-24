#include <stdio.h>
void naturalNum(int n)
{
    if (n > 0)
    {
        naturalNum(n - 1);
        printf("%d ", n);
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