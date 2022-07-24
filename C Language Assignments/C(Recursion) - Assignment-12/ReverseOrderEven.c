#include <stdio.h>
void print(int n)
{
    if (n > 0)
    {
        printf("%d ", 2*n);
        print(n - 1);
    }
}
int main()
{
    int n; 
    printf("Enter the value: ");
    scanf("%d",&n);
    print(n);
    return 0;
}